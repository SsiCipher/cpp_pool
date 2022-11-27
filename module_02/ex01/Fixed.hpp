#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_num_value;
		static const int	_fract_bits = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& num);

#endif
