/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:04:08 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/21 03:43:34 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __easyfind_H__
# define __easyfind_H__

# include <iostream>
# include <algorithm>
# include <iterator>
# include <exception>

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw() { return ("Look in another Container."); }
};

template <typename T> typename T::iterator easyfind(T &arr, int n)
{
	if (arr.empty())
		throw NotFound();
	typename T::iterator it = std::find(arr.begin(), arr.end(), n);
	if (*it == n)
		return (it);
	throw NotFound();
}

#endif
