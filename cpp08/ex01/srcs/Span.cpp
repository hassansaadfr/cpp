#include "Span.hpp"

Span::Span(void): _list(new int[0]()), _size(0)
{}

Span::Span(unsigned int N): _list(new int[N]()), _size(N)
{}

Span::~Span(void)
{
	delete [] _list;
}

Span::Span(Span const &src)
{
	if (this != &src)
	{
		_size = src._size;
		delete [] _list;
		_list = new int[_size]();
		for (unsigned int i = 0; i < src._size; i++)
			_list[i] = src._list[i];
	}
}

Span&	Span::operator=(Span const &src)
{
	_size = src._size;
	delete [] _list;
	_list = new int[_size]();
	for (unsigned int i = 0; i < src._size; i++)
		_list[i] = src._list[i];
	return *this;
}

void	Span::addNumber(int n)
{

}


int		&Span::getList(void) const
{
	return (*this->_list);
}
