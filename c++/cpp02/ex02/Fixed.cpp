/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:02:15 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/03 18:02:15 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value){
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value){
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) {
	return this->_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) {
	return this->_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) {
	return this->_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) {
	return this->_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) {
	return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) {
	return this->_value != other.getRawBits();
}



Fixed& Fixed::operator+(const Fixed& other) {
	Fixed *newFixed = new Fixed();
	newFixed->_value = roundf((this->toFloat() + other.toFloat()) * (1 << this->_bits));
	return *newFixed;
}

Fixed& Fixed::operator-(const Fixed& other) {
	Fixed *newFixed = new Fixed();
	newFixed->_value = roundf((this->toFloat() - other.toFloat()) * (1 << this->_bits));
	return *newFixed;
}

Fixed& Fixed::operator*(const Fixed& other) {
	Fixed *newFixed = new Fixed();
	newFixed->_value = roundf((this->toFloat() * other.toFloat()) * (1 << this->_bits));
	return *newFixed;
}

Fixed& Fixed::operator/(const Fixed& other) {
	Fixed *newFixed = new Fixed();
	newFixed->_value = roundf((this->toFloat() / other.toFloat()) * (1 << this->_bits));
	return *newFixed;
}

Fixed& Fixed::operator++() {
	this->_value++;//= 1<<this->_bits;
	return *this;
}

Fixed& Fixed::operator--() {
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << this->_bits);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_bits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


float Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a.getRawBits() : b.getRawBits();
}

float Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a.getRawBits() : b.getRawBits();
}

float Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a.getRawBits() : b.getRawBits();
}

float Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a.getRawBits() : b.getRawBits();
}