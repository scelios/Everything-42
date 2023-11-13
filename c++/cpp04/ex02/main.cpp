/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:18:29 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/03 15:18:29 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// delete meta;
	int number_of_animals = 2;
	Animal *animals[number_of_animals];
	for (int i = 0; i < number_of_animals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < number_of_animals; i++)
		delete animals[i];
	return 0;
}
