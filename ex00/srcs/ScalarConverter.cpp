/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:20:21 by codespace         #+#    #+#             */
/*   Updated: 2026/10/05 19:09:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() { }

static const void convert(const std::string &str) {
	eType type = getType(str);
	switch (type) {
		case CHAR:
			std::cout << "char : " << str[0] << std::endl;
			break;
		case INT:
			std::cout << "int :" << str[0] << std::endl;
			break;
		case FLOAT:
			std::cout << "float :" << str[0] << std::endl;
			break;
		case DOUBLE:
			std::cout << "double :" << str[0] << std::endl;
			break;
		case SPECIAL:
			std::cout << "special :" << str[0] << std::endl;
			break;
		default:
			std::cout << "type non pris en charge : " << str[0] << std::endl;
			return ;
	}
	doConvertion(str, type);
}
