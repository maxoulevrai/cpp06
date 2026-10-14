/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:38:50 by maleca            #+#    #+#             */
/*   Updated: 2026/10/14 18:45:19 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*original;
	Data		*deserialized;
	uintptr_t	raw;

	data.data1 = 42;
	original = &data;

	std::cout << "Original address:      " << original << std::endl;
	std::cout << "Original data1:        " << original->data1 << std::endl;

	raw = Serializer::serialize(original);
	std::cout << "Serialized value:      " << raw << std::endl;

	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized address:  " << deserialized << std::endl;
	std::cout << "Deserialized data1:    " << deserialized->data1 << std::endl;

	if (deserialized != original || deserialized->data1 != data.data1)
	{
		std::cout << "Pointer serialization test: FAIL" << std::endl;
		return (1);
	}
	std::cout << "Pointer serialization test: OK" << std::endl;

	if (Serializer::deserialize(Serializer::serialize(NULL)) != NULL)
	{
		std::cout << "NULL serialization test: FAIL" << std::endl;
		return (1);
	}
	std::cout << "NULL serialization test: OK" << std::endl;
	return (0);
}