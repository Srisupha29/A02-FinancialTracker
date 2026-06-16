#include <stdio.h>

#include "../include/transaction.h"

int main()
{
    Transaction *salary =
        createTransaction(
            INCOME,
            "Salary",
            1200
        );

    printf("Description: %s\n", salary->description);

    printf("Amount: %.2f\n", salary->amount);

    return 0;
}
