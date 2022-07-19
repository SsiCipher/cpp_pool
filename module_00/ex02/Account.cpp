#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

// ------------ Constructor

Account::Account(int initial_deposit)
{
	// account
	Account::_accountIndex = this->_nbAccounts;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	// total
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits += 1;
}

Account::~Account(void)
{

}

// ------------ Getters

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

// ------------ Others

void Account::makeDeposit(int deposit)
{
	if (deposit <= 0)
		return ;

	Account::_amount += deposit;
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
		return (false);

	Account::_amount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	return (Account::_amount);
}

void Account::displayStatus(void) const
{
	
}
