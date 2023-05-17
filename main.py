import pinecone
import numpy as np
import gradio as gr
from sentence_transformers import SentenceTransformer
from dotenv import load_dotenv

load_dotenv('config.env')
import os

pineconeapi_key = os.getenv('PINECONE_API_KEY')

pinecone.init(api_key=pineconeapi_key, environment="asia-southeast1-gcp-free")

index_name = "my-index"

model = SentenceTransformer('bert-base-nli-mean-tokens')

vec_text = {}
texts = [
    "The weather is sunny and warm.",
    "I love going to the beach and swimming in the ocean.",
    "Pizza is my all-time favorite food.",
    "I enjoy reading books and getting lost in different worlds.",
    "Traveling to new places broadens my perspective."
]
vectors = model.encode(texts)
vector_list = [{'id': f'vec{i}', 'values': vector} for i, vector in enumerate(vectors)]
vec_text = {f'vec{i}': text for i, text in enumerate(texts)}

pinecone.Index(index_name).upsert(vector_list)

query = gr.inputs.Textbox(label="Enter your query")

query_vector = model.encode([""]).tolist()
response = pinecone.Index(index_name).query(queries=query_vector, top_k=3)
sorted_results = sorted(response['results'], key=lambda x: x['matches'][0]['score'], reverse=True)
top_result = sorted_results[0]
top_match = top_result['matches'][0]
top_id = top_match['id']
top_score = top_match['score']
result_text = vec_text[top_id]

output = gr.outputs.Textbox(label="Most similar")

def query_similarity(query):
    query_vector = model.encode([query]).tolist()
    response = pinecone.Index(index_name).query(queries=query_vector, top_k=3)
    sorted_results = sorted(response['results'], key=lambda x: x['matches'][0]['score'], reverse=True)
    result_texts = []
    for result in sorted_results:
        result_texts.append(vec_text[result['matches'][0]['id']])
    result_string = '\n'.join(result_texts)
    return result_string







iface = gr.Interface(fn=query_similarity, inputs=query, outputs=output).launch(share=True)
url = iface.launch()
print(url)
