#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{			
	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(const int num);
		Fixed(const float fnum);
		~Fixed();
		
		float toFloat(void) const;
		int toInt(void) const;
		
		Fixed &operator=(Fixed const &rhs);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	
	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream &obj, Fixed &const fixed);

#endif