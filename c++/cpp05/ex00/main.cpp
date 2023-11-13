/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/12 16:03:59 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test1 = Bureaucrat("test1", 1);
	Bureaucrat test2 = Bureaucrat("test2", 150);
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	try
	{
		Bureaucrat test3 = Bureaucrat("test3", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	try
	{
		Bureaucrat test4 = Bureaucrat("test4", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
	return (0);
}