/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:21:11 by beaudibe          #+#    #+#             */
/*   Updated: 2023/10/27 11:52:56 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		std::string _str;
		int _int;
		float _float;
		double _double;
		char _char;
	public:
		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter &ref);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &ref);
		std::string getStr() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		char getChar() const;
		void setStr(std::string str);
		void convert();
		void print();
};

#endif