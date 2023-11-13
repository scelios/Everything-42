/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:30:01 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/13 18:11:09 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{
}

Form::Form(std::string _name, int sign, int execute) : _name(_name), _grade_to_sign(sign), _grade_to_execute(execute), _signed(false)
{
	if (sign < 1 || execute < 1)
		throw Form::GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute), _signed(other._signed)
{
	if (other._grade_to_sign < 1 || other._grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (other._grade_to_sign > 150 || other._grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "FormException: The Form is already signed";
}

Form &Form::operator=(Form const &other)
{
	this->_signed = other._signed;
	return (*this);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	else if (this->_signed)
		throw Form::FormAlreadySignedException();
	std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "(" << form.getName() << ")[" << ((form.getSigned()) ? "Signed" : "Unsigned")
		<< "]<Sign:" << form.getGradeToSign() << ",Execute:"
		<< form.getGradeToExecute() << ">";
	return (out);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

