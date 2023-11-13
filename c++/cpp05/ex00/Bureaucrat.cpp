/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:44:23 by beaudibe          #+#    #+#             */
/*   Updated: 2023/10/30 10:54:52 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Error, expected name and rank. Bureaucrat will not be used." << std::endl;
	_grade = -1;
}

Bureaucrat::Bureaucrat(std::string name, int rank)
{
	if (!name.empty())
		_name = name;
	else{
		std::cout << "Error, name cannot be empty" << std::endl;
		_grade = -1;
	}
	if (rank >= 1 && rank <= 150)
		_grade = rank;
	else{
		if (rank > 150)
			throw Bureaucrat::GradeTooHighException();
		else
			throw Bureaucrat::GradeTooLowException();
		_grade = -1;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(){}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ")";
	return (out);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 >= 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 <= 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}