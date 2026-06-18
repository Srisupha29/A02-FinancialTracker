#include <stdio.h>

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
