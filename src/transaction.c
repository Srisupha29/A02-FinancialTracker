#include <stdlib.h>
#include <string.h>

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
