/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:35:04 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/08 11:06:59 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"


ScravTrap::ScravTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_type = "ScravTrap ";
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScravTrap " << name << " constructor called" << std::endl;
}

ScravTrap::ScravTrap(ScravTrap const &ref) : ClapTrap(ref)
{
	std::cout << "ScravTrap copy constructor called" << std::endl;
}

ScravTrap::~ScravTrap()
{
	std::cout << "ScravTrap " << this->_name << " destructor called" << std::endl;
}

ScravTrap &ScravTrap::operator=(ScravTrap const &ref)
{
	_name = ref._name;
	_hitPoints = ref._hitPoints;
	_energyPoints = ref._energyPoints;
	_attackDamage = ref._attackDamage;
	return (*this);
}

void ScravTrap::guardGate()
{
	static bool gate = false;
	if (this->_name.empty())
		return;
	if (gate == false)
	{
		std::cout << "ScravTrap " << this->_name << " has enterred Gate keeper mode" << std::endl;
		gate = true;
	}
	else
	{
		std::cout << "ScravTrap " << this->_name << " has exit Gate keeper mode" << std::endl;
		gate = false;
	}
}