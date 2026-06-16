#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/transaction.h"

Transaction* createTransaction(
    TransactionType type,
    const char *description,
    double amount
)

{
    Transaction *node = malloc(sizeof(Transaction));

    node->type = type;

    strcpy(node->description, description);

    node->amount = amount;

    node->next = NULL;

    return node;
}

void insertAtEnd(
    Transaction **head,
    Transaction *newNode
)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Transaction *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void printTransactions(
    Transaction *head
)
{
    Transaction *current = head;

    int position = 1;

    while (current != NULL)
    {
        printf(
            "%d. %s %.2f\n",
            position,
            current->description,
            current->amount
        );

        current = current->next;
        position++;
    }
}
