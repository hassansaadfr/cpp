#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data
{
	public:
		Data(void);
		Data(int nb);
		~Data(void);
		Data(Data const &src);

		int			get_value(void) const;
		Data&		operator=(Data const &src);
		bool		operator==(Data const &src);
	private:
		int	_nb;
};

std::ostream &		operator<<(std::ostream &o, Data const &src);

#endif
