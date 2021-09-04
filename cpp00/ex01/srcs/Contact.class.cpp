#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void)
{
	this->remove();
}

Contact::~Contact(void)
{
	this->remove();
}

void	Contact::create(void)
{
	set_lastname(this->_prompt("lastname"));
	set_firstname(this->_prompt("firstname"));
	set_nickname(this->_prompt("nickname"));
	set_phone(this->_prompt("phone"));
	set_darkest_secret(this->_prompt("darkest secret"));
}

void	Contact::remove(void)
{
	this->_firstname.clear();
	this->_lastname.clear();
	this->_nickname.clear();
	this->_phone.clear();
	this->_darkest_secret.clear();
}

std::string	Contact::_prompt(std::string name) const
{
	std::string	buff;

	while (buff.length() < 3)
	{
		std::cout << "Please enter " << name << " : ";
		std::getline(std::cin, buff);
		if (std::cin.fail())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cout << std::endl << "Bye !" << std::endl;
				exit(0);
			}
		}
		if (buff.length() < 3)
		{
			std::cout << "3 chars minimum" << std::endl;
			std::cin.clear();
		}
	}
	std::cout << std::endl;
	return buff;
}

void		Contact::set_firstname(std::string str) { this->_firstname = str; }
void		Contact::set_lastname(std::string str) { this->_lastname = str; }
void		Contact::set_nickname(std::string str) { this->_nickname = str; }
void		Contact::set_phone(std::string str) { this->_phone = str; }
void		Contact::set_darkest_secret(std::string str) { this->_darkest_secret = str; }

std::string	Contact::get_firstname(void) const
{
	return this->_firstname;
}
std::string	Contact::get_lastname(void) const
{
	return this->_lastname;
}
std::string	Contact::get_nickname(void) const
{
	return this->_nickname;
}
std::string	Contact::get_phone(void) const
{
	return this->_phone;
}
std::string	Contact::get_darkest_secret(void) const
{
	return this->_darkest_secret;
}
