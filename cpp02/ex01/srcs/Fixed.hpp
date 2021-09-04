#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		Fixed(Fixed const &src);

		Fixed&				operator=(Fixed const &src);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					_value;
		static int	const	_bits = 8;
};

std::ostream &		operator<<(std::ostream &o, Fixed const &src);

#endif
