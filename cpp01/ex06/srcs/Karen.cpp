#include "Karen.hpp"
#include <iostream>

Karen::Karen(void) {}
Karen::~Karen(void) {}

Karen::Karen(std::string level)
{
	void		(Karen::*f[4])(void);
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	f[0] = &Karen::_debug;
	f[1] = &Karen::_info;
	f[2] = &Karen::_warning;
	f[3] = &Karen::_error;
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			for (size_t j = i; j < 4; j++)
				(this->*f[j])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Karen::_debug(void)
{
	std::cout << "Debug level: " << std::endl;
	std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!";
	std::cout << std::endl;
}
void	Karen::_info(void)
{
	std::cout << "Info level: " << std::endl;
	std::cout << "I cannot believe adding extrabacon cost more money. You don’t put enough! If you did I would not have to askfor it!";
	std::cout << std::endl;
}
void	Karen::_warning(void)
{
	std::cout << "Warning level: " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve beencoming here for years and you just started working here last month.";
	std::cout << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "Error level: " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}
