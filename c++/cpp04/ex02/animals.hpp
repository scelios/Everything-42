/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:08:16 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/04 10:08:16 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
# define ANIMALS_HPP

# include <iostream>
# include "brain.hpp"

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		virtual Animal &operator=(const Animal& other);
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif