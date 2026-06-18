#include <stdio.h>

#include "../include/transaction.h"
#include "../include/fileio.h"

int main()
{
    Transaction *head = NULL;

    insertAtEnd(
        &head,
        createTransaction(
            INCOME,
            "Salary",
            1200
        )
    );

    insertAtEnd(
        &head,
        createTransaction(
            EXPENSE,
            "Rent",
            800
        )
    );

    insertAtEnd(
        &head,
        createTransaction(
            EXPENSE,
            "Food",
            150
        )
    );

    insertAtPosition(
        &head,
        createTransaction(
            EXPENSE,
            "Internet",
            50
        ),
        2
    );

    deleteAtPosition(head, 3);

    printTransactions(head);

    saveTransactions(
         "logs/transaction_log.txt", head
    );

    printf("\nTransactions saved.\n");

    return 0;
}

    
            
                      
   

   
