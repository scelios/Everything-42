#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
}

Bitcoin::Bitcoin(std::string filename)
{
	if (filename.empty())
		throw std::runtime_error("Filename is empty");
	if (filename.find(".csv") == std::string::npos)
		throw std::runtime_error("Filename is not a .csv file");
	std::fstream file;
	file.open(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	while (std::getline(file, line))
	{
		add(line);
	}
	file.close();
}

Bitcoin::Bitcoin(Bitcoin const &other)
{
	*this = other;
}

Bitcoin &Bitcoin::operator=(Bitcoin const &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

Bitcoin::~Bitcoin()
{
}



void Bitcoin::print()
{
	std::map<std::string, double>::iterator it = _data.begin();
	while (it != _data.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

void Bitcoin::add(std::string line)
{
	if (line.empty())
		return;
	if (line.find(",") == std::string::npos)
		return;
	if (line.find("\n") != std::string::npos)
		line.erase(line.find("\n"));
	if (line.find("\r") != std::string::npos)
		line.erase(line.find("\r"));
	std::string date = line.substr(0, line.find(","));
	std::string price = line.substr(line.find(",") + 1);

	for (size_t i = 0; i < price.size(); i++)
	{
		if (isdigit(price[i]) == false && price[i] != '\r' && price[i] != '\n' && price[i] != '\t' && price[i] != '.' && price[i] != '-')
			return;
	}
	double priceDouble = std::atof(price.c_str());
	_data[date] = priceDouble;
}

void Bitcoin::add_file(std::string filename)
{
	if (filename.empty())
		throw std::runtime_error("Filename is empty");
	if (filename.find(".txt") == std::string::npos)
		throw std::runtime_error("Filename is not a .txt file");
	std::fstream file;
	file.open(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	while (std::getline(file, line))
		parse_line(line);
}

void Bitcoin::parse_line(std::string line)
{
	if (line.empty() == false && line.find("date | value") != std::string::npos)
		return;
	if (line.empty() || line.find("|") == std::string::npos 
	|| line.find(" ") == std::string::npos
	|| line.find("|") + 2 >= line.size())
	{
		std::cout << "Invalid line format" << std::endl;
		return;
	}
		
	if (line.find("\n") != std::string::npos)
		line.erase(line.find("\n"));
	if (line.find("\r") != std::string::npos)
		line.erase(line.find("\r"));
	std::string date = line.substr(0, line.find(" "));
	if (date.empty() || date.find("-") == std::string::npos || date.size() != 10)
	{
		std::cout << "Invalid line format" << std::endl;
		return;
	}
	std::string price = line.substr(line.find("|") + 2);
	double priceDouble = std::atof(price.c_str());
	if (price.empty() || priceDouble < 0 || priceDouble > 1000)
	{
		std::cout << "Invalid price" << std::endl;
		return;
	}
	show_result(date, priceDouble);
}

void Bitcoin::show_result(std::string date, double priceDouble)
{

	std::cout << date << " => " << priceDouble << " = ";
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it != _data.begin() && it->first != date)
		it--;
	std::cout << it->second * priceDouble << std::endl;
}