/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:43:39 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/06 10:46:13 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : brain(new Brain()){
	this->_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	this->_type = other._type;
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Wouf wouf" << std::endl;
}