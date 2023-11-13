/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:26:56 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/14 12:17:15 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Aform("default", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Aform("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Aform(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw Aform::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	static int i = 0;
	if (i++ % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
}
