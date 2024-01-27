/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:27:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/21 04:01:36 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vec(arr, arr + arr_size);

	try
	{
		for (int i = 0; i < 11; i++)
			std::cout << *easyfind(vec, i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
