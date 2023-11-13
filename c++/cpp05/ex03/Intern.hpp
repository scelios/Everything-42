/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:30:45 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/15 14:35:05 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Aform.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const& src);
		~Intern();
		Intern& operator=(Intern const& src);
		ShrubberyCreationForm* makeShrubberyCreationForm(std::string const& target);
		RobotomyRequestForm* makeRobotomyRequestForm(std::string const& target);
		PresidentialPardonForm* makePresidentialPardonForm(std::string const& target);
		Aform* makeForm(std::string const& formName, std::string const& target);
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif