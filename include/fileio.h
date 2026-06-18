#ifndef FILEIO_H
#define FILEIO_H

#include "transaction.h"

void saveTransactions(
    const char *filename,
    Transaction *head
);

#endif
