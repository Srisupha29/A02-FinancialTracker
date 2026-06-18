#include <stdio.h>

#include "../include/transaction.h"
#include "../include/fileio.h"

int main() 
{
    Transaction *head = NULL;

    char choice;

    printf("Resume previous session? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        head = loadTransactions(
            "logs/transaction_log.txt"
        );

        printf("\nPrevious session loaded.\n");
    }
    else
    {
        printf("\nStarting new session.\n");
    }

    printTransactions(head);

    return 0;
}

                  
    
              
            
            
      

    
          
