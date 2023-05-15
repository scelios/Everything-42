/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:45:35 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/03 17:53:59 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "address of string: " << &string << std::endl;
	std::cout << "address stocked in stringPTR: " << stringPTR << std::endl;
	std::cout << "address stocked in stringREF: " << &stringREF << std::endl;
	std::cout << "value of string: " << string << std::endl;
	std::cout << "value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;

	return 0;
}
