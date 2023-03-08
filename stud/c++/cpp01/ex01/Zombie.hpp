/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:57:53 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:32:57 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce();
		void set_name(std::string name);

	private:
		std::string name_;
};

Zombie*	zombieHorde(int N, std::string name);
void deleteZombieHorde(Zombie* horde);

#endif
