/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:41:40 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/06 10:46:03 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : brain(new Brain()){
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->_type = other._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	this->_type = other._type;
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaouuuuuuuuuuu" << std::endl;
}