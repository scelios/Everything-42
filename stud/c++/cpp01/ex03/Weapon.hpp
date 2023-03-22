/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:37:26 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 18:42:33 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const	&getType(void);
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif
