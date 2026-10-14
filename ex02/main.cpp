/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:42:00 by maleca            #+#    #+#             */
/*   Updated: 2026/10/14 19:42:00 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include "includes/Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Base	*generated;
	A		a;
	B		b;
	C		c;

	std::srand(std::time(NULL));
	std::cout << "Generated objects:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		generated = generate();
		std::cout << "Pointer identification:   ";
		identify(generated);
		std::cout << "Reference identification: ";
		identify(*generated);
		delete generated;
	}

	std::cout << std::endl << "Explicit objects:" << std::endl;
	std::cout << "A pointer:     ";
	identify(&a);
	std::cout << "B pointer:     ";
	identify(&b);
	std::cout << "C pointer:     ";
	identify(&c);
	std::cout << "A reference:   ";
	identify(a);
	std::cout << "B reference:   ";
	identify(b);
	std::cout << "C reference:   ";
	identify(c);

	std::cout << std::endl << "NULL pointer:  ";
	identify(static_cast<Base *>(NULL));
	return (0);
}
