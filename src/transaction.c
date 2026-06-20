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
    
    node->status = NEW;

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
            "%d. %s %.2f",
             position,
             current->description,
             current->amount
);

if (current->status == DELETED)
{
    printf(" --- d");
}

printf("\n");

        current = current->next;
        position++;
    }
}

double calculateBalance(
    Transaction *head
)
{
    double balance = 0;

    Transaction *current = head;

    while (current != NULL)
    {
        if (current->status != DELETED)
        {
            if (current->type == INCOME)
            {
                balance += current->amount;
            }
            else
            {
                balance -= current->amount;
            }
        }

        current = current->next;
    }

    return balance;
}

void insertAtPosition(
    Transaction **head,
    Transaction *newNode,
    int position
)
{
    if (position <= 1 || *head == NULL)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Transaction *current = *head;

    int currentPosition = 1;

    while (
        current->next != NULL &&
        currentPosition < position - 1
    )
    {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtPosition(
    Transaction *head,
    int position
)
{
    Transaction *current = head;

    int currentPosition = 1;

    while (
        current != NULL &&
        currentPosition < position
    )
    {
        current = current->next;
        currentPosition++;
    }

    if (current != NULL)
    {
        current->status = DELETED;
    }
}

void freeTransactions(
    Transaction *head
)
{
    Transaction *current = head;

    while (current != NULL)
    {
        Transaction *temp = current;

        current = current->next;

        free(temp);
    }
}
