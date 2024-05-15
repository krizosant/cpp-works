//5.Class BankAccount (W3Resource)
#include<iostream>

using namespace std;

class BankAccount
{
private:
	string accountNumber;
	double balance;
public:
	BankAccount(const string& pAccountNumber, double pBalance) : accountNumber(pAccountNumber), balance(pBalance) {} //Constructor
	void deposit(double pDepositAmount)
	{
		balance += pDepositAmount;
		cout << "Deposit successful! Current account balance: " << balance << endl;
	}
	void withdraw(double pWithdrawAmount)
	{
		if(balance < pWithdrawAmount)
		{
			cout << "Insufficient balance! Current account balance: " << balance << endl;
		}
		else
		{
			balance -= pWithdrawAmount;
			cout << "Withdraw successful! Current account balance: " << balance << endl;
		}
	}
};
