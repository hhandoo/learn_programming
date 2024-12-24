#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance; // Private data member

public:
    // Constructor
    BankAccount(double initialBalance)
    {
        balance = initialBalance;
    }

    // Public methods to access private data
    void deposit(double amount)
    {
        balance += amount;
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount account(1000.0); // Initial balance
    account.deposit(500.0);      // Deposit money
    cout << "Current Balance: " << account.getBalance() << endl;

    return 0;
}