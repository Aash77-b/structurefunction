# Simple Bank Account Management System

A lightweight C++ console application that demonstrates basic banking operations using **structs**, **pointers**, and **dynamic memory allocation**.

## ## Features

* **Dynamic Account Creation:** Define the number of accounts at runtime.
* **Deposit System:** Add funds to a specific account using its unique account number.
* **Withdrawal Logic:** Securely withdraw funds with a check for insufficient balance.
* **Data Overview:** Display a formatted table of all active accounts, names, and balances.
* **Memory Management:** Utilizes `new` and `delete[]` to manage memory efficiently during execution.

---

## ## Technical Implementation

The system uses a custom `struct` to group related data and a global pointer to manage an array of these structures:

```cpp
struct account {
    int no;
    string name;
    float balance;
};
```

### ### Key Functions
| Function | Description |
| :--- | :--- |
| `getdata()` | Initializes the dynamic array and collects user input for each account. |
| `deposit()` | Searches for an account by ID and increments the balance. |
| `withdraw()` | Validates the account ID and ensures funds are available before deducting. |
| `display()` | Outputs a tab-separated list of all stored accounts. |

### ### Prerequisites
* A C++ compiler (e.g., GCC/G++, Clang, or MSVC).

### ### Compilation and Execution
1.  **Compile the code:**
    ```bash
    g++ main.cpp -o bank_system
    ```
2.  **Run the application:**
    ```bash
    ./bank_system
    ```


## ## Usage Flow
1.  Upon startup, enter the **total number of accounts** you wish to manage.
2.  Input the **name**, **account number**, and **initial balance** for each user.
3.  Use the main menu to perform transactions.
4.  **Important:** Select option `4` to Exit, which triggers the `delete[]` command to free allocated memory and prevent leaks.

> **Note:** This program uses a `goto` loop for the main menu. While functional for small scripts, consider refactoring to a `do-while` loop for more complex projects!
