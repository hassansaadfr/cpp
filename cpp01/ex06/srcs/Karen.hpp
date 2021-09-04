#ifndef KAREN_CPP
# define KAREN_CPP

#include <iostream>

class Karen
{
	public:
		Karen(void);
		Karen(std::string level);
		~Karen(void);

		void	complain(std::string level);

	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

#endif
