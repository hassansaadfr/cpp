#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &src);

		Fixed&				operator=(Fixed const &src);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					_value;
		static int	const	_bits = 8;
};

std::ostream &		operator<<(std::ostream o, Fixed const &src);

#endif
