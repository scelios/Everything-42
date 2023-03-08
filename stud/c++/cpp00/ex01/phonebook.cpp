/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:57 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/07 05:19:47 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() {}
Contact::~Contact() {}

PhoneBook::PhoneBook() : contactCount_(0) {}

PhoneBook::~PhoneBook() {}

void Contact::setFirstName(std::string first_name)
{
    _first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	_last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string Contact::returnFirstName(void){
	return (_first_name);
}

std::string Contact::returnLastName(void){
	return (_last_name);
}

std::string Contact::returnNickame(void){
	return (_nickname);
}

std::string Contact::returnPhoneNumber(void){
	return (_phone_number);
}

std::string Contact::returnDarkestSecret(void){
	return (_darkest_secret);
}

void Contact::printContact() {
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

void PhoneBook::print1Contact() {
	int index;

	do  {
		std::cout << "Enter the index of the contact you want to print (0-" << contactCount_ - 1 << "): ";
		std::cin >> index;
	} while (index < 0 || index >= contactCount_);
	_contacts[index].printContact();
	std::cout << "Returning to main menu" << std::endl;
	std::cin.ignore();
}

void PhoneBook::addContact() {
	Contact new_contact;

	if (contactCount_ > MAX_CONTACTS - 1)
		contactCount_ = MAX_CONTACTS - 1;
	std::string line;
	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin, line);
	} while (line.empty());
	new_contact.setFirstName(line);
	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin, line);
	} while (line.empty());
	new_contact.setLastName(line);

	do {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, line);
	} while (line.empty());
	new_contact.setNickname(line);

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, line);
	} while (line.empty());
	new_contact.setPhoneNumber(line);

	do {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, line);
	} while (line.empty());
	new_contact.setDarkestSecret(line);

	PhoneBook::_contacts[PhoneBook::contactCount_] = new_contact;
	contactCount_++;

	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContact(){
	if (contactCount_ == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->contactCount_; i++) {
		
		std::cout << std::setw(10) << i << "|";
		if (this->_contacts[i].returnFirstName().length() > 10)
			std::cout << std::setw(9) << this->_contacts[i].returnFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].returnFirstName() << "|";
		if (this->_contacts[i].returnLastName().length() > 10)
			std::cout << std::setw(9) << this->_contacts[i].returnLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].returnLastName() << "|";
		if (this->_contacts[i].returnNickame().length() > 10)
			std::cout << std::setw(9) << this->_contacts[i].returnNickame().substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << std::setw(10) << this->_contacts[i].returnNickame() << "|" << std::endl;

	}
	PhoneBook::print1Contact();
}

int main() {
	PhoneBook phoneBook;

	std::string command;

	while (1) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			std::cout << "Goodbye" << std::endl;
			break;
		} else {
			std::cout << "Error, invalid input parameter, try with \"ADD\", \"SEARCH\" or \"EXIT\"\n";
		}
	}
	return 0;
}
