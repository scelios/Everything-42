/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/15 15:11:55 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "Aform.hpp"

int main()
{
	try
	{
		Intern intern;
		Aform *form = intern.makeForm("Presidential Pardon Form", "Bender");
		Bureaucrat a("a", 1);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}