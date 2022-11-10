#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ------------ Constructor

Account::Account(void)
{

}

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

	// msg
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
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

void	Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
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

	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";p_amount:" << Account::_amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << Account::_accountIndex;
		std::cout << ";p_amount:" << Account::_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	Account::_amount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";p_amount:" << Account::_amount + withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;

	return (true);
}

int Account::checkAmount(void) const
{
	return (Account::_amount);
}

void Account::displayStatus(void) const
{
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";deposits:" << Account::_nbDeposits;
	std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}
