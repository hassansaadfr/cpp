#include "Span.hpp"
#include <climits>

Span::Span(void): _maxSize(0)
{}

Span::Span(unsigned int N): _maxSize(N)
{}

Span::~Span(void)
{}

unsigned int	Span::longestSpan(void)
{
	_list.sort();
	if (_list.size() <= 1)
		throw Span::Error("Not enough numbers");
	return *--_list.end() - *_list.begin();
}

unsigned int	Span::shortestSpan(void)
{
	if (_list.size() <= 1)
		throw Span::Error("Not enough numbers");

	unsigned int	out = UINT_MAX;
	std::list<int>::const_iterator	current = _list.begin();
	std::list<int>::const_iterator	last = _list.end();

	_list.sort();
	while (current != last)
	{
		std::list<int>::const_iterator	tmp = current;
		++tmp;
		if (tmp == last)
			break ;
		unsigned int delta = *tmp - *current;
		if (delta < out)
			out = delta;
		current++;
	}
	return out;
}

Span::Span(Span const &src): _maxSize(src._maxSize), _list(src._list)
{}

Span&	Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_list = src._list;
		_maxSize = src._maxSize;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_list.size() == _maxSize)
		throw Span::Error("Cant add more number");
	_list.push_back(n);
}

const std::list<int>	&Span::getList(void) const
{
	return _list;
}

std::ostream &		operator<<(std::ostream &o, Span const &src)
{
	for (std::list<int>::const_iterator it = src.getList().begin(); it != src.getList().end(); it++)
		o << *it << std::endl;
	return o;
}
