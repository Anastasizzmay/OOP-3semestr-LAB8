#include "BankAccount.h"

void  BankAccount::show() {
	cout << "Настоящий баланс: " << this->balance << endl;
}

double  BankAccount::get()
{
	return this->balance;
}

void  BankAccount::set(double balance) {
	this->balance = balance;
}

void   BankAccount::withdraw(double sum) {
	balance -= sum;
}

void  BankAccount::replenish(double sum) {
	balance += sum;
}