#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <stdlib.h>

template <typename T>
class Array
{
	public:
		Array(void) : _elems(new T[0]()), _size(0) {};
		Array(unsigned int nb): _elems(new T[nb]()), _size(nb) {};
		~Array(void) { delete [] _elems; };

		Array&		operator=(Array const &src)
		{
			if (this != &src)
			{
				_size = src.size();
				delete [] _elems;
				_elems = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_elems[i] = src.elems[i];
			}
			return *this;
		}

		Array(Array const &src)
		{
			_size = src.size();
			_elems = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_elems[i] = src._elems[i];
		}

		T&				operator[](unsigned int i)
		{
			if (i >= _size)
				throw OutOfRange();
			return _elems[i];
		}

		unsigned int	size(void) const { return _size; };
	private:
		T				*_elems;
		unsigned int	_size;
	public:
		class OutOfRange: public std::exception
		{
			 virtual const char* what() const throw() { return ("Out of range."); }
		};
};

template <typename T>
std::ostream &		operator<<(std::ostream &o, Array<T> const &src)
{
	o << src._elems;
	return o;
}

#endif
