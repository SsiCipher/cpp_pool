#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "This is a debug message\n";
}

void Harl::info(void)
{
	std::cout << "This is an info message\n";
}

void Harl::warning(void)
{
	std::cout << "This is a warning message\n";
}

void Harl::error(void)
{
	std::cout << "This is an error message\n";
}

void Harl::complain(std::string level)
{
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "ERROR: " << level << " is not a valid level\n";
	}
	else
	{
		void (Harl::*levels[4])(void) = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error};

		(this->*levels[(level == "DEBUG") * 0 + (level == "INFO") * 1 + (level == "WARNING") * 2 + (level == "ERROR") * 3])();
	}
}
