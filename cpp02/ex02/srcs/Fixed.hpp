#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);

		~Fixed(void);

		Fixed&				operator=(Fixed const &src);
		Fixed&				operator+(Fixed const &src);
		Fixed&				operator-(Fixed const &src);
		Fixed&				operator*(Fixed const &src);
		Fixed&				operator/(Fixed const &src);

		bool				operator>(Fixed const &src);
		bool				operator<(Fixed const &src);
		bool				operator>=(Fixed const &src);
		bool				operator<=(Fixed const &src);
		bool				operator==(Fixed const &src);
		bool				operator!=(Fixed const &src);

		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed 			&min(Fixed &a, Fixed &b);
		static Fixed 			&max(Fixed &a, Fixed &b);

		static const Fixed 		&min(Fixed const &a, Fixed const &b);
		static const Fixed 		&max(Fixed const &a, Fixed const &b);
	private:
		int					_value;
		static int	const	_bits = 8;
};

std::ostream &		operator<<(std::ostream &o, Fixed const &src);

#endif
