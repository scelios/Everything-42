/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:59:36 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/05 12:05:45 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap :public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &ref);
		~FragTrap();
		FragTrap &operator=(FragTrap const &ref);
		void highFivesGuys();
};

#endif