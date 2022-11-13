#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon human_weapon)
{
    this->name = human_name;
    this->weapon = human_weapon;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << this->name + " attacks with their " + this->weapon.getType() << "\n";
}
