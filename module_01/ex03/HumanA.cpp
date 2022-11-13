#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon &human_weapon): weapon(human_weapon)
{
    this->name = human_name;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << this->name + " attacks with their " + this->weapon.getType() << "\n";
}
