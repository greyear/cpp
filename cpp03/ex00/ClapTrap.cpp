
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	
}

ClapTrap::ClapTrap(const ClapTrap& other):
	_name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{

}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{

}