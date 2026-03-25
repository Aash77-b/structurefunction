#include<iostream>
using namespace std;

struct account {
    int no;
    string name;
    float balance;
};

void deposit();
void withdraw();
void getdata();
void display();

int n;
account *a;

int main() {
    getdata();

    do{
    char choice;
    cout << "\nwould you like to 1)deposit \n2)withdraw \n3)Display\n4)Exit: ";
    cin >> choice;

    switch(choice) {
        case '1':
            deposit();
            break;
        case '2':
            withdraw();
            break;
        case '3':
            display();
            break;
        case '4':
            delete[] a;
            return 0;
    }
    }while(true);
    return 0;
}

void deposit() {
    int amount, accnum;
    cout << "Enter account number: ";
    cin >> accnum;
    cout << "Enter amount: ";
    cin >> amount;
    for(int i = 0; i < n; i++) {
        if(a[i].no == accnum) {
            a[i].balance = a[i].balance + amount;
            cout << "New balance: " << a[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void withdraw() {
    int amount, accnum;
    cout << "Enter account number: ";
    cin >> accnum;
    cout << "Enter amount: ";
    cin >> amount;


    for(int i = 0; i < n; i++) {
        if(a[i].no == accnum) {

            if(amount <= a[i].balance) {
                a[i].balance = a[i].balance - amount;
                cout << "New balance: " << a[i].balance << endl;
            } else {
                cout << "Insufficient balance! Current balance: " << a[i].balance << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void getdata() {
    cout << "How many accounts? ";
    cin >> n;


    a = new account[n];

    for(int i = 0; i < n; i++) {
        cout << "\n--- Account " << i + 1 << " ---" << endl;
        cout << "Enter Name " << i + 1 << ": ";
        cin >> a[i].name;
        cout << "Enter account number: ";
        cin >> a[i].no;
        cout << "Enter balance: ";
        cin >> a[i].balance;

        if(a[i].balance < 0) {
            cout << "Balance cannot be negative. Setting to 0." << endl;
            a[i].balance = 0;
        }
    }
}

void display() {
    cout << "\nacc_number\tName\tBalance\n";
    for(int i = 0; i < n; i++) {
        cout << a[i].no << "\t\t" << a[i].name << "\t\t" << a[i].balance << endl;
    }
    cout << endl;
}
