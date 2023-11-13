#ifndef BITCOIN
# define BITCOIN

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include <map>
#include <fstream>
#include <cstdlib>
#include <stdexcept>


class Bitcoin
{
private :
	Bitcoin();
	std::map<std::string, double> _data;
public :
	Bitcoin(std::string filename);
	Bitcoin(Bitcoin const &other);
	Bitcoin &operator=(Bitcoin const &other);
	~Bitcoin();
	void show_result(std::string date,double amount);
	void add(std::string line);
	void add_file(std::string filename);
	void parse_line(std::string line);
	void print();

};

#endif