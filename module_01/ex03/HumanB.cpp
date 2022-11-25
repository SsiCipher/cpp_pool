#include "HumanB.hpp"

HumanB::HumanB(std::string human_name)
{
    this->name = human_name;
    this->weapon = nullptr;
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon &human_weapon)
{
    this->weapon = &human_weapon;
}

void HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " doesn't have any weapon to attack with!" << std::endl;
}
