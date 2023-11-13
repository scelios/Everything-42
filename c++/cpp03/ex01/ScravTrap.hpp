/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:35:12 by beaudibe          #+#    #+#             */
/*   Updated: 2023/09/05 11:43:12 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{
	public:
		ScravTrap(std::string name);
		ScravTrap(ScravTrap const &ref);
		~ScravTrap();
		ScravTrap &operator=(ScravTrap const &ref);
		void guardGate();
};

#endif