/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:20:21 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 13:50:50 by codespace        ###   ########.fr       */
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
	if (type == UNKNOWN) {
		std::cout << "type non pris en charge : " << str[0] << std::endl;
		return ;
	}
	doConvert(str, type);
}
