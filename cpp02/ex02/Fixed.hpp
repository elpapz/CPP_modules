#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		bool operator>(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &fp1, Fixed &fp2);
		static Fixed &max(Fixed &fp1, Fixed &fp2);
		static Fixed const &min(Fixed const &fp1, Fixed const &fp2);
		static Fixed const &max(Fixed const &fp1, Fixed const &fp2);

		int	getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream& stream, Fixed const& obj);

#endif