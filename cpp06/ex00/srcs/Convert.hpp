#ifndef CONVERT_H
# define CONVERT_H

# include <iostream>

class Convert
{
	public:
		Convert(void);
		Convert(char *value);
		~Convert(void);
		Convert(Convert const &src);

		Convert&		operator=(Convert const &src);

		char			to_char(void) const;
		int				to_int(void) const;
		float			to_float(void) const;
		double			to_double(void) const;
		double			get_value(void) const;
	private:
		double			_value;
	public:
		class	impossibleCast: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream &		operator<<(std::ostream &o, Convert const &src);

#endif
