# A02: Advanced Personal Finance Tracker

## Student Information

* Name: Srisupha Chawla
* Course: System Skills 
* Assignment: A02 – Advanced Personal Finance Tracker

---

# 1. Introduction

The purpose of this project is to develop a Personal Finance Tracker using the C programming language. The application allows users to manage income and expense transactions, calculate balances, save transaction history, and resume previous sessions. The project demonstrates linked lists, dynamic memory allocation, file handling, modular programming, and build automation using Makefiles.

---

# 2. Program Structure

The project is divided into the following components:

## main.c

Responsible for:

* User interaction
* Command processing
* Program control flow

## transaction.c / transaction.h

Responsible for:

* Creating transactions
* Linked list management
* Transaction insertion
* Transaction deletion
* Balance calculation
* Memory cleanup

## fileio.c / fileio.h

Responsible for:

* Saving transactions
* Loading transactions
* Session persistence

## Makefile

Responsible for:

* Compilation
* Cleaning build files
* Distribution packaging

---

# 3. Data Structure Design

The application stores transactions using a singly linked list.

Each transaction node contains:

* Transaction type (Income or Expense)
* Description
* Amount
* Transaction status
* Pointer to the next node

Example:

```c
typedef struct Transaction {
    TransactionType type;
    char description[100];
    double amount;
    TransactionStatus status;
    struct Transaction *next;
} Transaction;
```

## Advantages of Linked Lists

* Dynamic memory allocation
* No fixed transaction limit
* Easy insertion at arbitrary positions
* Efficient traversal
* Suitable for continuously growing data

---

# 4. Features Implemented

## Session Management

* Start a new session
* Resume a previous session
* Load transactions from file

## Transaction Management

* Add income transactions
* Add expense transactions
* Insert transactions at specified positions
* Edit existing transactions
* Delete transactions

## Transaction Status Tracking

The program uses three status markers:

* `(saved)` for transactions loaded from file
* `+++ i` for newly inserted transactions
* `--- d` for deleted transactions

## Financial Analysis

* Display all transactions
* Calculate account balance
* Budget status indicator

## File Handling

* Save transactions to transaction_log.txt
* Load transactions from transaction_log.txt
* Preserve data between executions

## Memory Management

* Dynamic allocation using malloc()
* Memory cleanup using freeTransactions()

## Build Automation

Supported Makefile commands:

```bash
make
make clean
make dist
```

---

# 5. Important Functions

### createTransaction()

Creates a new transaction node.

### insertAtPosition()

Inserts a transaction at a user-specified position.

### deleteAtPosition()

Marks a transaction as deleted.

### editTransaction()

Updates transaction information.

### calculateBalance()

Computes the user's financial balance.

### saveTransactions()

Stores transaction data in transaction_log.txt.

### loadTransactions()

Loads transaction data from transaction_log.txt.

### freeTransactions()

Releases dynamically allocated memory.

---

# 6. Testing

The following tests were successfully completed:

| Test                      | Result |
| ------------------------- | ------ |
| Add income                | Passed |
| Add expense               | Passed |
| Insert at beginning       | Passed |
| Insert at middle          | Passed |
| Insert at end             | Passed |
| Edit transaction          | Passed |
| Delete transaction        | Passed |
| Calculate balance         | Passed |
| Save session              | Passed |
| Load session              | Passed |
| Invalid position handling | Passed |
| Negative amount handling  | Passed |

---

# 7. Screenshots

The following screenshots were collected:

1. Loading a previous session successfully
2. Linked list showing (saved) markers
3. Linked list showing +++ i markers
4. Linked list showing --- d markers
5. Inserting a transaction at a specific position
6. Editing a transaction
7. Deleting a transaction
8. Negative amount validation
9. Invalid position validation
10. Updated transaction_log.txt after saving

---

# 8. Conclusion

The Advanced Personal Finance Tracker successfully demonstrates linked list implementation, dynamic memory management, file persistence, modular software design, and Makefile-based build automation. The application fulfills the assignment requirements by supporting transaction insertion, editing, deletion, balance calculation, and session persistence while maintaining data integrity across program executions.

