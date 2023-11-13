/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:31:53 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/14 11:32:20 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Aform.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Aform
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& src);
	void execute(Bureaucrat const& executor) const;
};

#endif