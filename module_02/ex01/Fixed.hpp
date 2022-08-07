#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					num_value;
		static const int	num_fract = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
