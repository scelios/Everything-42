/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:29:30 by beaudibe          #+#    #+#             */
/*   Updated: 2023/10/31 15:46:47 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str(0){}

ScalarConverter::ScalarConverter(std::string str) : _str(str){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	*this = ref;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	_str = ref._str;
	_int = ref._int;
	_float = ref._float;
	_double = ref._double;
	_char = ref._char;
	return (*this);
}

std::string ScalarConverter::getStr() const { return (_str);}

int ScalarConverter::getInt() const{ return (_int);}

float ScalarConverter::getFloat() const{ return (_float);}

double ScalarConverter::getDouble() const{ return (_double);}

char ScalarConverter::getChar() const{ return (_char);}

void ScalarConverter::setStr(std::string str){ _str = str;}

void ScalarConverter::convert()
{
	if (_str == "nan" || _str == "nanf" || _str == "-inff" || _str == "+inff" || _str == "-inf" || _str == "inf")
	{
		return ;
	}
	_int = std::atoi(_str.c_str());
	_float =std::atof(_str.c_str());
	_double = std::atof(_str.c_str());
	if (_char >= 32 && _char <= 126)
		return;
	_char = _int;
}

void ScalarConverter::print()
{
	if (_str == "nan" || _str == "nanf" || _str == "-inff" || _str == "+inff" || _str == "-inf" || _str == "inf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;

	}
	if (_char >= 32 && _char <= 126)
		std::cout << "char: " << _char <<std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}
