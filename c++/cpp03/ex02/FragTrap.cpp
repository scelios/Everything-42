/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:58:44 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/08 11:07:07 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_type = "FragTrap ";
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref) : ClapTrap(ref)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &ref)
{
	_name = ref._name;
	_hitPoints = ref._hitPoints;
	_energyPoints = ref._energyPoints;
	_attackDamage = ref._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	if (this->_name.empty())
		return;
	std::cout << "FragTrap " << this->_name << " has requested a high five" << std::endl;
}