#ifndef EASYFIND_H
#define EASYFIND_H

#include <vector>

class NotExist: public std::exception
{
	virtual const char* what() const throw() { return ("Cant find value"); }
};

template < typename T>
int &easyfind(T &container, int n)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == n)
			return *it;
	}
	throw NotExist();
}

#endif
