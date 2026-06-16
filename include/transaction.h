#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef enum {
    INCOME,
    EXPENSE
} TransactionType;

typedef struct Transaction {
    TransactionType type;
    char description[100];
    double amount;

    struct Transaction *next;
} Transaction;

Transaction* createTransaction(
    TransactionType type,
    const char *description,
    double amount
);

#endif
