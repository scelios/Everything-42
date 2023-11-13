/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Afform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:30:01 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/14 11:02:32 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Bureaucrat.hpp"

Aform::Aform() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{
}

Aform::Aform(std::string _name, int sign, int execute) : _name(_name), _grade_to_sign(sign), _grade_to_execute(execute), _signed(false)
{
	if (sign < 1 || execute < 1)
		throw Aform::GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw Aform::GradeTooLowException();
}

Aform::Aform(Aform const &other) : _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute), _signed(other._signed)
{
	if (other._grade_to_sign < 1 || other._grade_to_execute < 1)
		throw Aform::GradeTooHighException();
	if (other._grade_to_sign > 150 || other._grade_to_execute > 150)
		throw Aform::GradeTooLowException();
}

Aform::~Aform()
{
}

const char* Aform::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Aform::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char* Aform::FormAlreadySignedException::what() const throw()
{
	return "FormException: The Form is already signed";
}

const char* Aform::FormNotSignedException::what() const throw()
{
	return "FormException: The Form is not signed";
}

Aform &Aform::operator=(Aform const &other)
{
	this->_signed = other._signed;
	return (*this);
}

void Aform::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Aform::GradeTooLowException();
	else if (this->_signed)
		throw Aform::FormAlreadySignedException();
	std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	this->_signed = true;
}

void Aform::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_grade_to_execute)
		throw Aform::GradeTooLowException();
	else if (!this->_signed)
		throw Aform::FormNotSignedException();
}

std::ostream &operator<<(std::ostream &out, Aform const &form)
{
	out << "(" << form.getName() << ")[" << ((form.getSigned()) ? "Signed" : "Unsigned")
		<< "]<Sign:" << form.getGradeToSign() << ",Execute:"
		<< form.getGradeToExecute() << ">";
	return (out);
}

std::string Aform::getName() const
{
	return (this->_name);
}

int Aform::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int Aform::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

bool Aform::getSigned() const
{
	return (this->_signed);
}

