/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:59:50 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:32:42 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "A Zombie is born!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name_ << " is destroyed!" << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name_ = name;
}

void Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
