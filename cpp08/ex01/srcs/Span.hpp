#ifndef SPAN_H
# define SPAN_H

# include <iostream>

class CantAdd: public std::exception
{
	virtual const char* what() const throw() { return ("Cant number"); }
};
class NoNumber: public std::exception
{
	virtual const char* what() const throw() { return ("There is no number"); }
};
class OneNumber: public std::exception
{
	virtual const char* what() const throw() { return ("Not enough numbers"); }
};

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(Span const &src);

		Span&				operator=(Span const &src);
		void				addNumber(int n);
		int					&getList(void) const;
		bool				empty(void) const;
	private:
		unsigned int		_size;
		int					*_list;
};

// std::ostream &		operator<<(std::ostream &o, Span const &src);

#endif
