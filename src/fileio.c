#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/fileio.h"

void saveTransactions(
    const char *filename,
    Transaction *head
)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Transaction *current = head;

    while (current != NULL)
    {
        if (current->status != DELETED)
        {
            if (current->type == INCOME)
            {
                fprintf(
                    file,
                    "INC|%s|%.2f\n",
                    current->description,
                    current->amount
                );
            }
            else
            {
                fprintf(
                    file,
                    "EXP|%s|-%.2f\n",
                    current->description,
                    current->amount
                );
            }
        }

        current = current->next;
    }

    fclose(file);
}

Transaction* loadTransactions(
    const char *filename
)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return NULL;
    }

    Transaction *head = NULL;

    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        char typeStr[10];
        char description[100];
        double amount;

        sscanf(
            line,
            "%[^|]|%[^|]|%lf",
            typeStr,
            description,
            &amount
        );

        TransactionType type;

        if (strcmp(typeStr, "INC") == 0)
        {
            type = INCOME;
        }
        else
        {
            type = EXPENSE;
            amount = -amount;
        }

        Transaction *node =
            createTransaction(
                type,
                description,
                amount
            );

        node->status = SAVED;

        insertAtEnd(
            &head,
            node
        );
    }

    fclose(file);

    return head;
}
