from transformers import BlenderbotTokenizer, BlenderbotForConditionalGeneration
from datetime import datetime
import gradio as gr
import mysql.connector
import torch
chatHistory = list(range(1000))
datewiseHistory = list(range(1000))
mname = "facebook/blenderbot-400M-distill"
model = BlenderbotForConditionalGeneration.from_pretrained(mname)
tokenizer = BlenderbotTokenizer.from_pretrained(mname)

cnx = mysql.connector.connect(
    host='localhost',
    user='root',
    password='P@pireddy340',
    database='chat_history'
)

cursor = cnx.cursor()

def retrieveUserChatsDateRange(user_id,begin,end):
    history = []
    user = "user_"+str(user_id)
    chatQuery = f"SELECT text FROM {user} WHERE timestamp BETWEEN '{begin}' AND '{end}'"
    cursor.execute(chatQuery)
    results = cursor.fetchall()
    for res in results:
        history.append(res[0])
    result = "\n".join(history)
    string = ''.join(result)
    return str(string)

def chatsToDatabase(sender, text, user_id):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    table_name = "user_"+str(user_id)
    create_table_query = f"CREATE TABLE IF NOT EXISTS {table_name} (text VARCHAR(100), sender VARCHAR(10), timestamp DATETIME)"
    insert_query = f"INSERT INTO {table_name} (text, sender, timestamp) VALUES (%s, %s, %s)"
    values = (text, sender, timestamp)

    try:
        cursor.execute(create_table_query)
        cursor.execute(insert_query, values)
        cnx.commit()
    except Exception as e:
        cnx.rollback()
        print("Failed to save chat history:", str(e))

def retrieveChatsbyUserid(user_id):
    history = []
    user = "user_" + str(user_id)
    chatQuery = f"SELECT text FROM {user}"
    cursor.execute(chatQuery)
    results = cursor.fetchall()
    for res in results:
        history.append(res[0])
    result = "\n".join(history)
    return str(result)



def response(input_text, user_id,filters,begin,end,seeChats):
    if filters=="filter by Date":
        chatHistory = retrieveUserChatsDateRange(user_id,begin,end)
        
    elif filters=="filter by User ID":
        chatHistory = retrieveChatsbyUserid(user_id)
        

    inputs = tokenizer([input_text], return_tensors="pt")
    reply_ids = model.generate(**inputs)
    response = tokenizer.batch_decode(reply_ids)
    chatsToDatabase("User", input_text, user_id)
    chatsToDatabase("Bot", response[0][3:-4], user_id)
    if seeChats:
        return response[0][3:-4],chatHistory 
    else:
        return response[0][3:-4]


user_id_input = gr.inputs.Textbox(label="User ID", placeholder="Enter User ID...")
input_text = gr.inputs.Textbox(lines=2, placeholder="Enter your message...")
filters = gr.Dropdown(["filter by User ID","filter by Date"],label="chats")
begin = gr.inputs.Textbox(label="begin-Date",placeholder="begin Date")
end = gr.inputs.Textbox(label="end-Date",placeholder="end Date")
hist = gr.inputs.Checkbox(label="chat history?")
output_text = gr.outputs.Textbox()
chatBox = gr.outputs.Textbox()
outputs = [
    gr.outputs.Textbox(label="Response Text")
]

if hist.value:
    outputs.append(gr.outputs.Textbox(label="Chat History"))

iface = gr.Interface(
    fn=response,
    inputs=[input_text, user_id_input, filters, begin, end, hist],
    outputs=outputs,
    title="Chatbot"
)
iface.launch()




