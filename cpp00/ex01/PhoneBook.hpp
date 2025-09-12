#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	int count;

public:
	PhoneBook();
	void addContact(const Contact &c);
	void displayContacts() const;
	void displayContact(int i) const;
	int getCount() const;
};

#endif