/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:20:21 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 17:13:06 by maleca           ###   ########.fr       */
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
