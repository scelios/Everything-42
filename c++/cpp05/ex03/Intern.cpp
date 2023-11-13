/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:31:54 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/15 15:09:42 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const& src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(Intern const& src)
{
	(void)src;
	return *this;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

Aform * Intern::makeForm(std::string const& formName, std::string const& target)
{
	Aform *form = NULL;
	std::string formNameLower = formName;
	for (int i = 0; formNameLower[i]; i++)
		formNameLower[i] = std::tolower(formNameLower[i]);
	Aform *formList[3] = {new RobotomyRequestForm(target),
							new PresidentialPardonForm(target),
							new ShrubberyCreationForm(target)};
	std::string formNameUpper[3] = {"robotomy", "presidential", "shrubbery"};
	for (int i = 0; i < 3; i++)
	{
		if (formNameLower.find(formNameUpper[i]) != std::string::npos
			&& formNameLower.find(formNameUpper[(i + 1) % 3]) == std::string::npos
			&& formNameLower.find(formNameUpper[(i + 2) % 3]) == std::string::npos)
			form = formList[i];
	}
	if (!form)
		throw Intern::FormNotFoundException();
	std::cout << "Intern creates " << formName << std::endl;
	return form;
}