/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:16:29 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/01 18:16:29 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (!name.empty()) {
		_name = name;
		std::cout << "ClapTrap " << _name << " created" << std::endl;
	} else {
		_name = "";
		std::cout << "ClapTrap creation failed: Name cannot be empty." << std::endl;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	_name = ref._name;
	_hitPoints = ref._hitPoints;
	_energyPoints = ref._energyPoints;
	_attackDamage = ref._attackDamage;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
}

ClapTrap::~ClapTrap(){
	if (!_name.empty())
		std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
	else
		std::cout << "ClapTrap destroyed" << std::endl;
}

bool	ClapTrap::CheckStatus()
{
	if (_name.empty())
	{
		return false;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return false;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack(std::string const &target)
{
	if (CheckStatus() == false)
		return ;
	if (_attackDamage == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack! He doesn't have hand !!!" << std::endl;
		return ;
	}
	if (target.empty())
	{
		std::cout << "ClapTrap " << _name << " attack nobody, causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
	else
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (CheckStatus() == false)
		return ;
	std::cout << "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (CheckStatus() == false)
		return ;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " points of damage!" << std::endl;
	_hitPoints += amount;
}

