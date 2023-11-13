/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/14 13:14:42 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Aform.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		PresidentialPardonForm b("b");
		a.signForm(b);
		b.execute(a);
		a.executeForm(b);
		RobotomyRequestForm c("c");
		a.signForm(c);
		c.execute(a);
		ShrubberyCreationForm d("d");
		a.signForm(d);
		d.execute(a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}