#include "PhoneBook.hpp"

std::string getInput(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting program due to EOF.\n";
			return "";
		}
		if (!input.empty())
			break;
		std::cout << "Field cannot be empty. Please try again.\n";
	}
	return input;
}

std::string getPhone(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting program due to EOF.\n";
			return "";
		}
		if (input.empty())
		{
			std::cout << "Phone number cannot be empty. Please try again.\n";
			continue;
		}
		int valid = 1;
		for (size_t i = 0; i < input.size(); ++i)
		{
			if (!isdigit(input[i]))
			{
				valid = 0;
				break;
			}
		}
		if (valid)
			break;
		std::cout << "Invalid phone number.\n";
	}
	return input;
}

void addContact(PhoneBook &phonebook)
{
	Contact contact;

	contact.setFirstName(getInput("First Name: "));
	contact.setLastName(getInput("Last Name: "));
	contact.setNickname(getInput("Nickname: "));
	contact.setPhoneNumber(getPhone("Phone Number: "));
	contact.setDarkestSecret(getInput("Darkest Secret: "));

	phonebook.addContact(contact);
	std::cout << "Contact added!\n";
}

void searchContact(PhoneBook &phonebook)
{
	if (phonebook.getCount() == 0)
	{
		std::cout << "No contacts to display.\n";
		return;
	}
	phonebook.displayContacts();

	std::string input;
	std::cout << "Enter index to view details: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << "\nExiting program due to EOF.\n";
		return;
	}
	int valid = 1;
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]))
		{
			valid = 0;
			break;
		}
	}
	if (!valid || input.empty())
	{
		std::cout << "Invalid input.\n";
		return;
	}
	int index = 0;
	for (size_t i = 0; i < input.length(); ++i)
		index = index * 10 + (input[i] - '0');

	phonebook.displayContact(index);
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nExiting program due to EOF.\n";
			break;
		}
		if (command == "ADD")
			addContact(phonebook);
		else if (command == "SEARCH")
			searchContact(phonebook);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command.\n";
	}
}