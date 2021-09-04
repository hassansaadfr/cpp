/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:53:16 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/08/11 12:53:17 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype>

int	main(int ac, char **av)
{
	std::locale loc;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; av[i]; i++)
			for (size_t j = 0; j < std::strlen(av[i]); j++)
				std::cout << std::toupper(av[i][j], loc);
		std::cout << std::endl;
	}
	return 0;
}
