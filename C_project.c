#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Admin();
int main()
{
    char enter, P;
    int choose, noofseats, pin = 123456, one, date, location, hydtheatre, gorpay, vjwtheatre, i, payment, noofitems, seat_no1, seat_no2, food, seat_no3, seat_no4, movie_name, comfort, cost, total_cost, convenience_fees;
    int dates[] = {7, 8, 9, 10};
    float time;
    int item_no1, item_no2, item_no3;

    system("cls");
    printf("*************************************** --BookMyShow!It all starts here--***************************************\n");
    printf("\t\t\t\t\t\t\n--press ENTER to proceed--\n");

    scanf("%c", &enter);

    system("cls");

    printf("\t\t\t\t\t\t\t\tPlease Choose an option from below\n");

USER:
    printf("\t\t\t\t\t\t\t\t1.USER (For Booking tickets)\n\t\t\t\t\t\t\t\t2.ADMIN (To edit titles or change ticket fare)\n");
    scanf("%d", &choose);
    if (choose > 2)
    {
        printf("\nPlease select a valid option (1 or 2)\n");
        goto USER;
    }
    else
    {
        switch (choose)
        {
        case 1:
        {
            system("cls");

        LOCATION:
            printf("\t\t\t\t\t\t\t\tPlease Choose your Location(press 1 for vijayawada)\n");
            printf("\t\t\t\t\t\t\t\t1.Vijayawada\n\t\t\t\t\t\t\t\t2.Hyderabad\n");
            scanf("%d", &location);
            if (location > 2)
            {
                printf("\nINVALID CHOICE!!! Please enter a valid choice (1 or 2)\n");
                goto LOCATION;
            }

            system("cls");
            switch (location)
            {
            case 2:
            {
            HYDTHEATRE:
                printf("\t\t\t\t\t\t\t\tPlease Choose a Theatre\n");
                printf("\t\t\t\t\t\t\t\t1.Shanthi Theatre\n\t\t\t\t\t\t\t\t2.Prashanth Theatre\n");
                scanf("%d", &hydtheatre);
                if (hydtheatre > 2)
                {
                    printf("INVALID CHOICE!!! Please enter a valid choice (1 or 2)\n\n");
                    goto HYDTHEATRE;
                }

                goto MOVIE;
            }
            case 1:
            {
            VJWTHEATRE:
                printf("\t\t\t\t\t\t\t\tPlease Choose a Theatre\n");
                printf("\t\t\t\t\t\t\t\t1.INOX LEPL Icon - Patamata\n\t\t\t\t\t\t\t\t2.INOX Urvasi Complex\n\t\t\t\t\t\t\t\t3.Capital Cinemas\n");
                scanf("%d", &vjwtheatre);
                if (vjwtheatre > 3)
                {
                    printf("INVALID CHOICE!!! Please enter a valid choice (1,2 or 3)\n\n");
                    goto VJWTHEATRE;
                }

                system("cls");
            MOVIE:
            {

                printf("\t\t\t\t\t\t\t\t1.Pushpa\n\t\t\t\t\t\t\t\t2.spiderman:no way home\n\t\t\t\t\t\t\t\t3.akhanda\n");
                scanf("%d", &movie_name);
                if (movie_name > 3)
                {
                    printf("INVALID CHOICE!!! Please enter a valid choice (1,2 or 3)\n\n");
                    goto MOVIE;
                }

                system("cls");

            DATE:
                printf("\t\t\t\t\t\t\t\tchoose the date\n");
                printf("\t\t\t\t\t\t\t\t%d\t%d\t%d\t%d\n\t\t\t\t\t\t\t\tMar\tMar\tMar\tMar\n", dates[0], dates[1], dates[2], dates[3]);
                scanf("%d", &date);
                if (date > 13)
                {
                    printf("\nPlease choose date with in the range\n");
                    goto DATE;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\tPlease select your time:\n");
                printf("\t\t\t\t\t\t\t\t11.00 am\t2.00pm\t5.30pm\t9.00pm\n");
                scanf("%f", &time);
                system("cls");
                printf("      \t\t\t\t\tAll eyes this way please\n");
                printf("\t\t\t-----------------------------------------\n");
                printf("\t\t\t||                Screen               ||\n");
                printf("\t\t\t-----------------------------------------\n\n\n\n\n");

                for (i = 1; i <= 10; i++)
                {

                    printf("     %d  ", i);
                }
                printf("\n");
                printf("\t\t");

                for (i = 11; i <= 100; i++)
                {

                    if (i % 10 == 1)
                    {
                        printf("\n\n");
                    }

                    printf("     %d ", i);
                }

            COMFORT:
                printf("\n\nBalcony\t Normal\n 100\t  70");
                printf("\npress 1 for balcony || press 2 for normal seats\n");
                scanf("%d", &comfort);
                if (comfort > 2)
                {
                    printf("\nINVALID CHOICE!!! Please enter a valid choice (1 or 2)\n");
                    goto COMFORT;
                }

                printf("\nSelect your seats\n");
                printf("1\t2\t3\t4\n");
                scanf("%d", &noofseats);

                switch (noofseats)
                {
                case 1:
                {
                    printf("Select one seat : ");
                    scanf("%d", &seat_no1);
                    system("cls");
                    if (seat_no1 <= 100)
                        printf("Your seat number is %d\n", seat_no1);
                    else
                        printf("\nthere are only 100 seats in this theatre\n");

                    break;
                }
                case 2:
                {
                    printf("Select two seats: ");
                    scanf("%d %d", &seat_no1, &seat_no2);
                    if (seat_no1 == seat_no2)
                    {
                        printf("\nplease choose different seats\n");
                    }
                    else
                    {
                        system("cls");
                        if (seat_no1 <= 100 && seat_no2 <= 100)

                            printf("\nYour seat numbers are %d %d", seat_no1, seat_no2);
                        else
                            printf("\nthere are only 100 seats in this theatre\n");
                        break;
                    }
                }
                case 3:
                {
                    printf("Select three seats: ");
                    scanf("%d %d %d", &seat_no1, &seat_no2, &seat_no3);

                    if (seat_no1 == seat_no2 == seat_no3)
                    {
                        printf("\nplease choose different seats\n");
                    }

                    else
                    {
                        system("cls");
                        if (seat_no1 <= 100 && seat_no2 <= 100 && seat_no3 <= 100)
                            printf("\nYour seat numbers are %d %d %d", seat_no1, seat_no2, seat_no3);
                        else
                            printf("\nthere are only 100 seats in this theatre\n");
                        break;
                    }
                }
                case 4:
                {
                    printf("Select four seats: ");
                    scanf("%d %d %d %d", &seat_no1, &seat_no2, &seat_no3, &seat_no4);
                    if (seat_no1 == seat_no2 == seat_no3 == seat_no4)
                    {
                        printf("\nplease choose different seats\n");
                    }

                    else
                    {

                        system("cls");
                        if (seat_no1 <= 100 && seat_no2 <= 100 && seat_no3 <= 100 && seat_no4 <= 100)

                            printf("\nYour seat numbers are %d %d %d %d\n", seat_no1, seat_no2, seat_no3, seat_no4);
                        else
                            printf("\nthere are only 100 seats in this theatre\n");
                        break;
                        break;
                    }
                }
                default:
                {
                    printf("Please enter no of seats < 5\n");
                    return 0;
                }
                }
                if (comfort == 1)
                {
                    cost = noofseats * 100;
                    convenience_fees = cost / 10;
                    total_cost = cost + convenience_fees;
                }
                else
                {
                    cost = noofseats * 70;
                    convenience_fees = cost / 10;
                    total_cost = cost + convenience_fees;
                }
            }

                int noofitems;
                printf("\nDo you want to have any snacks for break time?(press 1 if yes , press 2 to continue without snacks order)\n");
                scanf("%d", &food);
                if (food == 1)
                {
                    printf("REFRESHMENTS:\n\n1. Samosa - 10 per piece\n2. Popcorn - 80 per bucket\n3. Soft drinks - 50 per cup\n");
                    printf("Enter the item number and the number of items you would like to have\n");
                    int item, n;
                    int price[] = {0, 10, 80, 50};
                    for (int i = 1; i <= 3; i++)
                    {
                        scanf("%d %d", &item, &n);
                        total_cost = total_cost + price[item] * n;
                    }
                    goto PAYMENT;
                }
                else
                {
                PAYMENT:
                    printf("Choose your Payment Method\n1.Paytm\n2.phonepay\n3.Gpay\n");
                    scanf("%d", &payment);

                    printf("Total payment is %d", total_cost);
                    scanf("%c", &P);
                    printf("\nEnter 6 digit UPI PIN\n");
                    scanf("%d", &pin);
                    if (pin != 123456)
                        printf("Wrong pin!\n");
                    else
                        printf("Payment done\n");
                }
                system("cls");

                switch (movie_name)
                {
                case 1:
                {
                    switch (vjwtheatre)
                    {
                    case 1:
                    {
                        printf("----------------INOX LEPL Icon - Patamata----------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d               Movie Name:Pushpa\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 2:
                    {
                        printf("------------------INOX Urvasi Complex -------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d               Movie Name:Pushpa\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 3:
                    {
                        printf("--------------------Capital Cinemas ---------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d               Movie Name:Pushpa\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    }

                    switch (hydtheatre)
                    {
                    case 1:
                    {
                        printf("----------------Shanthi Theatre,Hyderbad ----------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                Movie Name:Pushpa\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 2:
                    {
                        printf("--------------------Prashanth Theatre--------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                Movie Name:Pushpa\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    }
                }

                break;
                case 2:
                {
                    switch (vjwtheatre)
                    {
                    case 1:
                    {
                        printf("--------------------INOX LEPL Icon - Patamata ---------------------\n");
                        printf("===================================================================\n");
                        printf("Booking ID=%d                 Movie Name:Spiderman No Way Home\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("===================================================================\n");
                        break;
                    }
                    case 2:
                    {
                        printf("-----------------------INOX Urvasi Complex -------------------------\n");
                        printf("====================================================================\n");
                        printf("Booking ID=%d                 Movie Name:Spiderman No Way Home\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=====================================================================\n");
                        break;
                    }
                    case 3:
                    {

                        printf("------------------------Capital Cinemas---------------------------\n");
                        printf("==================================================================\n");
                        printf("Booking ID=%d                 Movie Name:Spiderman No Way Home\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("===================================================================\n");
                        break;
                    }
                    }

                    switch (hydtheatre)
                    {
                    case 1:
                    {

                        printf("-------------------------Shanthi Theatre---------------------------\n");
                        printf("===================================================================\n");
                        printf("Booking ID=%d                 Movie Name:Spiderman No Way Home\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("===================================================================\n");
                        break;
                    }
                    case 2:
                    {

                        printf("------------------------Prashanth Theatre-------------------------\n");
                        printf("==================================================================\n");
                        printf("Booking ID=%d                 Movie Name:Spiderman No Way Home\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("==================================================================\n");
                        break;
                    }
                    }
                }
                break;

                case 3:
                {
                    switch (vjwtheatre)
                    {
                    case 1:

                    {

                        printf("----------------INOX LEPL Icon - Patamata ----------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                 Movie Name:Akhanda\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 2:
                    {

                        printf("------------------INOX Urvasi Complex ------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                 Movie Name:Akhanda\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 3:
                    {

                        printf("---------------------Capital Cinemas---------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                 Movie Name:Akhanda\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    }
                    break;
                }

                    switch (hydtheatre)
                    {
                    case 1:
                    {

                        printf("--------------------Shanthi Theatre----------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                 Movie Name:Akhanda\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    case 2:
                    {

                        printf("------------------Prashanth Theatre------------------\n");
                        printf("=========================================================\n");
                        printf("Booking ID=%d                 Movie Name:Akhanda\n");
                        printf("                                       Show time:%.2f\n", time);
                        printf("                                       Date: %d/03/2022\n", date);
                        printf("                                       No of seats= %d\n", noofseats);
                        printf("                                       price=%d\n", total_cost);
                        printf("=========================================================\n");
                        break;
                    }
                    }
                    break;
                }
                break;
            }
            break;
            }
            break;
        }
        case 2:
        {
            Admin();
            exit(0);
        }
        }
    }
    int cancel;

    printf("Want to cancel the ticket?(press 1 for cancelling) otherwise ignore this\nRemember if you cancel the ticket ,10%% from the total cost of the ticket will be deducted\n");
    scanf("%d", &cancel);
    if (cancel == 1)
    {
        float fine;
        fine = (10.0 / 100) * (total_cost);
        printf("Your ticket has been cancelled\n");
        printf("You have been charged %0.2f for the cancellation of tickets and %0.2f will be refunded to your account shortly\n", fine, (total_cost - fine));
    }
}

void Admin()
{
    char password[30] = "12345", entered[30];
    char title1[100] = "1. Doctor Strange Multiverse of Madness", title2[100] = "2. Spider-Man Across the Spiderverse", title3[100] = "3. Morbius";
    char *ptr1 = title1, *ptr2 = title2, *ptr3 = title3;
    int balcony = 100, normal = 70;
    printf("Enter the PASSWORD\n");
    scanf("%s", entered);
    system("cls");
    if (strcmp(entered, password) != 0)
    {
        printf("WRONG PASSWORD!!!\n");
    }
    else
    {
        int choice;
        printf("LOGIN SUCCESSFUL!!!\n\n");
    CHOICE:
        printf("Enter your choice\n1.Edit movie title\n2.Edit ticket price\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            int choice;
        TITLE:
            printf("Enter the index of the movie you want to replace\n%s\n%s\n%s\n", title1, title2, title3);
            scanf("%d", &choice);
            system("cls");
            switch (choice)
            {
            case 1:
                printf("Enter the new title:\n");
                scanf(" %[^\n]s", ptr1);
                printf("The new movie list is:\n1. %s\n%s\n%s", title1, title2, title3);
                break;

            case 2:
                printf("Enter the new title:\n");
                scanf(" %[^\n]s", ptr2);
                printf("The new movie list is:\n%s\n2. %s\n%s", title1, title2, title3);
                break;

            case 3:
                printf("Enter the new title:\n");
                scanf(" %[^\n]s", ptr3);
                printf("The new movie list is:\n%s\n%s\n3. %s", title1, title2, title3);
                break;

            default:
                printf("Please enter a valid choice\n\n");
                goto TITLE;
                break;
            }
        }

        else if (choice == 2)
        {
            system("cls");
            printf("Choose the price you want to change\n1.BALCONY\t100\n2.NORMAL\t70\n");
        PRICE:
            scanf("%d", &choice);
            system("cls");
            switch (choice)
            {
            case 1:
                printf("Enter the new price of the balcony tickets\n");
                scanf("%d", &balcony);
                printf("The new prices of the tickets are\n1.BALCONY\t%d\n2.NORMAL\t%d\n", balcony, normal);
                break;

            case 2:
                printf("Enter the new price of the normal tickets\n");
                scanf("%d", &normal);
                printf("The new prices of the tickets are\n1.BALCONY\t%d\n2.NORMAL\t%d\n", balcony, normal);
                break;

            default:
                printf("Please enter a valid choice\n");
                goto PRICE;
                break;
            }
        }

        else
        {
            system("cls");
            printf("Please enter a valid choice\n\n");
            goto CHOICE;
        }
    }
}
