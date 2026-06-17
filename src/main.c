#include <stdio.h>

#include "../include/transaction.h"

int main()
{
    Transaction *head = NULL;

    Transaction *salary =
        createTransaction(
            INCOME,
            "Salary",
            1200
        );

    Transaction *rent =
        createTransaction(
            EXPENSE,
            "Rent",
            800
        );

    Transaction *food =
        createTransaction(
            EXPENSE,
            "Food",
            150
        );

    insertAtEnd(&head, salary);

    insertAtEnd(&head, rent);

    insertAtEnd(&head, food);

    printTransactions(head);

    double balance = calculateBalance(head);

    printf("\nBalance: %.2f\n", balance);

    if (balance >= 0)
    {
        printf("Status: Within Budget\n");
    }
    else
    {
        printf("Status: Over Budget\n");
    }

    return 0;
}
