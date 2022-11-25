#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	else
	{
		switch (
			(level == "DEBUG") * 0 + (level == "INFO") * 1 + (level == "WARNING") * 2 + (level == "ERROR") * 3)
		{
		case 0:
			Harl::debug();
			Harl::info();
			Harl::warning();
			Harl::error();
			break;

		case 1:
			Harl::info();
			Harl::warning();
			Harl::error();
			break;

		case 2:
			Harl::warning();
			Harl::error();
			break;

		case 3:
			Harl::error();
			break;

		default:
			break;
		}
	}
}
