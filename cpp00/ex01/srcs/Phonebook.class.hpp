#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class Phonebook {

private:

	bool	_is_full(void) const;
	void	_print_value(std::string str) const;
	void	_print_list(void) const;

public:

	size_t		size;
	Contact		contact_list[8];

	Phonebook(void);
	~Phonebook(void);

	int		execute_cmd(std::string cmd);
	void	new_contact(void);
	void	search_contact(void) const;
	void	add_contact(Contact contact);
};

#endif
