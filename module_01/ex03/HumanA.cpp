#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon &human_weapon): _weapon(human_weapon)
{
    this->_name = human_name;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << this->_name + " attacks with their " + this->_weapon.getType() << std::endl;
}
