#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int								_num_value;
		static const int	_num_fract = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
