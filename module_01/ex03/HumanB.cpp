#include "HumanB.hpp"

HumanB::HumanB(std::string human_name)
{
    this->name = human_name;
    this->weapon = NULL;
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
    std::cout << this->name + " attacks with their " + this->weapon->getType() << "\n";
}
