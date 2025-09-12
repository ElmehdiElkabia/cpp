#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0) {}

void PhoneBook::addContact(const Contact &c)
{
	contacts[index] = c;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

std::string format(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << format(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << format(contacts[i].getLastName()) << "|"
				  << std::setw(10) << format(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int i) const
{
	if (i < 0 || i >= count || i >= 8)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
}

int PhoneBook::getCount() const
{
	return count;
}