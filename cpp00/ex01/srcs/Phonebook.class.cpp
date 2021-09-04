#include <iostream>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
	this->size = 0;
}

Phonebook::~Phonebook(void)
{
	return ;
}

bool	Phonebook::_is_full(void) const
{
	return this->size >= 8;
}

void	Phonebook::new_contact(void)
{
	Contact	contact;
	if (!this->_is_full())
		this->contact_list[this->size++].create();
	else
	{
		std::cout << "The phonebook is full the last contact will be overwritten" << std::endl;
		this->contact_list[this->size - 1].remove();
		this->contact_list[this->size - 1].create();
	}
}

void	print_delimitation(void)
{
	for (size_t i = 0; i < 52; i++)
		std::cout << "_";
}

void	Phonebook::_print_list(void) const
{
	print_delimitation();
	std::cout << std::endl << "|";
	this->_print_value("ID");
	std::cout << " | ";
	this->_print_value("Lastname");
	std::cout << " | ";
	this->_print_value("Firstname");
	std::cout << " | ";
	this->_print_value("Nickname");
	std::cout << " |" << std::endl;
	print_delimitation();
	std::cout << std::endl;
	for (size_t i = 1; i <= this->size; i++)
	{
		std::cout << "|";
		this->_print_value(std::to_string(i));
		std::cout << " | ";
		this->_print_value(this->contact_list[i - 1].get_lastname());
		std::cout << " | ";
		this->_print_value(this->contact_list[i - 1].get_firstname());
		std::cout << " | ";
		this->_print_value(this->contact_list[i - 1].get_nickname());
		std::cout << " |" << std::endl;
		if (this->size > 0)
			print_delimitation();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int	id_is_valid(std::string str, int max)
{
	int	id;

	if (str.empty())
		return (-1);
	else if (str.find_first_not_of("0123456789") != std::string::npos)
		return (-2);
	id = std::stoi(str);
	if (id >= 1 && id <= max)
		return (1);
	return (0);
}

void	Phonebook::search_contact(void) const
{
	std::string str;
	int			id;

	this->_print_list();
	if (this->size > 0)
	{
		std::cout << "Enter id: " << std::endl;
		while (id_is_valid(str, this->size) != 1)
		{
			std::getline(std::cin, str);
			if (std::cin.fail() || id_is_valid(str, this->size) != 1)
			{
				if (id_is_valid(str, this->size) == -1)
					std::cout << "Id is empty!" << std::endl;
				else if (id_is_valid(str, this->size) == -2)
					std::cout << "Id must contain only digits!" << std::endl;
				else if (id_is_valid(str, this->size) == 0)
					std::cout << "Id must be between 1 and " << this->size << std::endl;
				std::cout << "Enter id: ";
				std::cin.clear();
				str.clear();
			}
		}
		id = std::stoi(str);
		std::cout << std::endl << "Lastname: " << this->contact_list[id - 1].get_lastname() << std::endl;
		std::cout << "Firstname: " << this->contact_list[id - 1].get_firstname() << std::endl;
		std::cout << "Nickname: " << this->contact_list[id - 1].get_nickname() << std::endl;
		std::cout << "Phone: " << this->contact_list[id - 1].get_phone() << std::endl;
		std::cout << "Darkest secret: " << this->contact_list[id - 1].get_darkest_secret() << std::endl << std::endl;
	}
	return ;
}

int	Phonebook::execute_cmd(std::string cmd)
{
	std::cout << std::endl;
	if (cmd == "ADD")
		this->new_contact();
	else if (cmd == "SEARCH")
		this->search_contact();
	else if (cmd == "EXIT")
		return (0);
	return (1);
}

void	Phonebook::_print_value(std::string str) const
{
	if (str.size() < 10)
	{
		for (size_t i = str.size(); i < 10; i++)
				std::cout << " ";
		std::cout << str;
	}
	else
		std::cout << str.substr(0, 9) << ".";
}
