/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:22:56 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 13:15:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isSpecial(const std::string &str) {
	if (str == "-inff" || str == "+inff" || str == "nanf " || str == "-inf" || str == "+inf"
		|| str == "nan")
		return (true);
	else
		return (false);
}

eType	getType(const std::string &str) {
	if (str.length() == 1) {
		if (!isdigit(str[0]))
			return CHAR;
		else
			return INT;
	}
	else if (str.find('.') != std::string::npos) {
		if (str.find('f') != std::string::npos)
			return FLOAT;
		else
			return DOUBLE;
	}
	else if (isSpecial(str))
		return SPECIAL;
	else
		return UNKNOWN;
}

