#include "Phonebook.class.hpp"
#include <iostream>

int main(void)
{
	Phonebook book;
	std::string buff;
	int running = 1;

	std::cout << "Welcome to your awesome phonebook" << std::endl
			  << std::endl;
	while (running)
	{
		std::cout << "Allowed commands :" << std::endl << "ADD, SEARCH, EXIT" << std::endl
				  << std::endl;
		std::getline(std::cin, buff);
		if (std::cin.fail())
		{
			std::cout << "Bye" << std::endl;
			break ;
		}
		running = book.execute_cmd(buff);
	}
	return 0;
}
