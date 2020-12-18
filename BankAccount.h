#pragma once
#include <iostream>
using namespace std;

class BankAccount {
private:
	double balance;
public:
	BankAccount() {
		balance = 0;
	}

	BankAccount(double balance) {
		this->balance = balance;
	}

	void show();
	void withdraw(double sum); //�����
	void replenish(double sum); //���������
	double get();
	void set(double balance);
};

