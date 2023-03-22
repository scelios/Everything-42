/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:58:18 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:43:38 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	int number_of_zombies = 0;
	if (argc != 3)
	{
		std::cout << "Usage: ./a.out <number of zombies> <Name of the horde>" << std::endl;
		return (1);
	}
	while (argv[1][number_of_zombies])
	{
		if (!isdigit(argv[1][number_of_zombies]))
		{
			std::cout << "Number of zombies must be a number" << std::endl;
			return (1);
		}
		number_of_zombies++;
	}
	number_of_zombies = atoi(argv[1]);
	deleteZombieHorde(zombieHorde(number_of_zombies , argv[2]));
	return (0);
}
