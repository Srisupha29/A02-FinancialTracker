#include <stdio.h>
#include <string.h>

#include "../include/transaction.h"
#include "../include/fileio.h"

int main()
{
    Transaction *head = NULL;

    char choice;

    printf("Resume previous session? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        head = loadTransactions(
            "logs/transaction_log.txt"
        );

        printf("\nPrevious session loaded.\n");
    }
    else
    {
        printf("\nStarting new session.\n");
    }

    char command[100];
    char description[100];
    double amount;
    int position;

    while (1)
    {
        printf("\nCommand: ");

        scanf(" %99[^\n]", command);

        if (strcmp(command, "add income") == 0)
        {
            printf("Description: ");
            scanf(" %99[^\n]", description);

            printf("Amount: ");
            scanf("%lf", &amount);
            
            printf("Position: ");
            scanf("%d", &position);

            Transaction *node =
                createTransaction(
                    INCOME,
                    description,
                    amount
                );
            insertAtPosition(
               &head,
               node,  
               position
            );

            printf("Income added.\n");
        }
        else if (strcmp(command, "add expense") == 0)
        {
            printf("Description: ");
            scanf(" %99[^\n]", description);

            printf("Amount: ");
            scanf("%lf", &amount);

            printf("Position: ");
            scanf("%d", &position);

            Transaction *node =
                createTransaction(
                    EXPENSE,
                    description,
                    amount
                );

            insertAtPosition(
                &head,
                node,
                position
            );
                    
            printf("Expense added.\n");
        }
        else if (strcmp(command, "print") == 0)
        {
            printTransactions(head);

            double balance =
                calculateBalance(head);

            printf(
                "\nBalance: %.2f\n",
                balance
            );
        }
        else if (strcmp(command, "quit") == 0)
        {
            saveTransactions(
                "logs/transaction_log.txt",
                head
            );

            printf("Session saved.\n");

            break;
        }
        else if (strncmp(command, "delete ", 7) == 0)
        {
           sscanf(command, "delete %d", &position);

           deleteAtPosition(
               head,
               position
           );

           printf(
               "Transaction %d deleted.\n",
               position
           );
       }
       else
       {
            printf("Unknown command.\n");
       }
    }

    return 0;
}
