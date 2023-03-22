/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:34:25 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/07 05:10:02 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

/*typedef struct s_contact{
	char first_name[60];
	char last_name[60];
	char nickname[60];
	char phone_number[60];
	char darkest_secret[60];
}	t_contact;*/

class Contact
{
	public:
		Contact();
		~Contact(void);
		void		setFirstName(std::string first_name);
		void		setLastName(std::string last_name);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phone_number);
		void		setDarkestSecret(std::string darkest_secret);
		void		printContact(void);
		std::string	returnFirstName(void);
		std::string	returnLastName(void);
		std::string	returnNickame(void);
		std::string	returnPhoneNumber(void);
		std::string	returnDarkestSecret(void);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

	void print1Contact();
    void addContact();
    void searchContact();
    void printContactList();

private:
    static const int MAX_CONTACTS = 8;
    Contact _contacts[MAX_CONTACTS];
    int contactCount_;
};
#endif

