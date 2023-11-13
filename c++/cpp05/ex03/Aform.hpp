/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:07:20 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/14 13:10:30 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Aform
{
	private:
		std::string const _name;
		int const _grade_to_sign;
		int const _grade_to_execute;
		bool _signed;
	public:
		Aform();
		Aform(std::string name, int grade_to_sign, int grade_to_execute);
		Aform(Aform const& src);
		virtual ~Aform();
		virtual Aform& operator=(Aform const& src);
		void beSigned(Bureaucrat const& src);
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSigned() const;
		virtual void execute(Bureaucrat const& executor) const = 0;
		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class FormAlreadySignedException: public std::exception {
			virtual const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Aform const& form);

#endif