#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					_value;
		static const int	_bits = 8;
};

#endif
