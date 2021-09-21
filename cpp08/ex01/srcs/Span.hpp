#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <list>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(Span const &src);

		Span&					operator=(Span const &src);
		void					addNumber(int n);

		template< typename Iterator >
		void					addNumber(Iterator begin, Iterator end)
		{
			while (begin != end)
				addNumber(*begin++);
		}
		unsigned int			shortestSpan(void);
		unsigned int			longestSpan(void);
		const std::list<int>	&getList(void) const;
	private:
		unsigned int		_maxSize;
		std::list<int>		_list;
	public:
		class Error: public std::exception
		{
			public:
				Error(void) : _what("Error") {};
				Error(const char* what): _what(what) {};
				virtual const char* what() const throw() { return _what; };
			private:
				const char*	_what;
		};

};

std::ostream &		operator<<(std::ostream &o, Span const &src);

#endif
