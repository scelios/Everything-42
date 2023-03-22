/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:59:50 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:26:05 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {
	std::cout << "Zombie " << name_ << " is born!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name_ << " is destroyed!" << std::endl;
}

void Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
