/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:07:20 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/13 18:01:48 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		int const _grade_to_sign;
		int const _grade_to_execute;
		bool _signed;
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(Form const& src);
		~Form();
		Form& operator=(Form const& src);
		void signForm();
		void beSigned(Bureaucrat const& src);
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSigned() const;
		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class FormAlreadySignedException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif