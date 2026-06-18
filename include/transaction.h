#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef enum {
    INCOME,
    EXPENSE
} TransactionType;

typedef enum {
    SAVED,
    NEW,
    DELETED
} TransactionStatus;

typedef struct Transaction {
    TransactionType type;
    char description[100];
    double amount;
    
    TransactionStatus status;

    struct Transaction *next;
} Transaction;


Transaction* createTransaction(
    TransactionType type,
    const char *description,
    double amount
);

void insertAtEnd(
    Transaction **head,
    Transaction *newNode
);

void printTransactions(
    Transaction *head
);

double calculateBalance(
    Transaction *head
);

void insertAtPosition(
    Transaction **head,
    Transaction *newNode,
    int position
);

void deleteAtPosition(
    Transaction *head,
    int position
);

#endif

