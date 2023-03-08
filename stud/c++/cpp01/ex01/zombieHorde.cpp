/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:58:36 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:42:32 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = -1;
	Zombie* horde = new Zombie[N];

	while (++i < N)
	{
		horde[i].set_name(name);
		horde[i].announce();
	}
	return (horde);
}

void deleteZombieHorde(Zombie* horde) {
    delete[] horde;
}
