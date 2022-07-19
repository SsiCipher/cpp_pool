#include <iostream>
#include "Account.hpp"

int main(void)
{
	Account acc(12);

	std::cout << "NbAccounts: " << acc.getNbAccounts() << "\n";
	std::cout << "TotalAmount: " << acc.getTotalAmount() << "\n";

	return (0);
}
