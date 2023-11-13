/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:11:14 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/04 10:11:14 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"

Animal::Animal() {
	this->_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	this->_type = other._type;
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
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

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
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