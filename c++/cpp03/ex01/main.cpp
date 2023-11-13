/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:16:41 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/01 18:16:41 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScravTrap.hpp"

int main()
{
	ScravTrap clapTrap("Bill");
	clapTrap.attack("Bob");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
	clapTrap.guardGate();
	clapTrap.guardGate();
	clapTrap.guardGate();

	return (0);
}