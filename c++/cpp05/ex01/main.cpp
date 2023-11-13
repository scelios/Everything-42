/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/13 18:16:29 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("b1", 1);
		std::cout << bob << std::endl;
		Form form("f1", 150, 150);
		std::cout << form << std::endl;
		bob.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bob("b2", 2);
		std::cout << bob << std::endl;
		Form form("f2", 1, 1);
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bob("b3", 1);
		std::cout << bob;
		Form form("f3", 1, 1);
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		form.beSigned(bob);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bob("b4", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	try
	{
		Bureaucrat bob("b5", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
	return (0);
}