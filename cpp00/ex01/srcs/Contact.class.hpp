#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact {
	public:

		// Constructor & Destructor
		Contact(void);
		~Contact(void);

		// Utils
		void	create(void);
		void	remove(void);

		// Setters
		void	set_firstname(std::string str);
		void	set_lastname(std::string str);
		void	set_nickname(std::string str);
		void	set_phone(std::string str);
		void	set_darkest_secret(std::string str);

		// Getters

		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_darkest_secret(void) const;

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkest_secret;

		std::string	_prompt(std::string name) const;
};

#endif
