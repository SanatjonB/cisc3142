#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance = 0;
public:
    void setAccountHolder(const string& name) {
        accountHolder = name; // storing the name 
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount; // money goes up
            cout << amount << " deposited. New balance: " << balance << endl;
        } else {
            cout << "bro deposit a positive amount"<<endl;
        }
    }
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "withdraw something real"<<endl;
            return;
        }
        if (amount > balance) {
            cout << "you don't got that much bro"<<endl;
            return;
        }
        balance -= amount; // money goes down
        cout << amount << " withdrawn. New balance: "<<balance << endl;
    }

    void checkBalance() const {
    cout << "Account holder: " << accountHolder << " Balance: "<< balance<< endl; 
    }
};
int main() {
    BankAccount acc;
    string name;
    cout << "Enter account holder's name: ";
    getline(cin, name);
    acc.setAccountHolder(name);
    // initial bread 
    acc.deposit(1000);
    acc.checkBalance();
    double dep;
    cout << "Enter amount to deposit: ";
    cin >> dep;
    acc.deposit(dep);
    acc.checkBalance();

    double wd;
    cout << "Enter amount to withdraw: ";
    cin >> wd;
    acc.withdraw(wd);
    acc.checkBalance();
    return 0;
}
