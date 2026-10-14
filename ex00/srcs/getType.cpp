/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:22:56 by codespace         #+#    #+#             */
/*   Updated: 2026/10/11 00:53:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isSpecial(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

static bool isDigits(const std::string &str, std::size_t begin,
					 std::size_t end)
{
	std::size_t i = begin;

	if (i == end)
		return (false);
	while (i < end)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		++i;
	}
	return (true);
}

static bool isInteger(const std::string &str)
{
	std::size_t begin = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	return (begin < str.length() && isDigits(str, begin, str.length()));
}

static bool isDecimal(const std::string &str, bool suffix)
{
	std::size_t end = str.length();
	std::size_t begin = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	std::size_t dot;
	bool hasDigitsBefore;
	bool hasDigitsAfter;

	if (suffix)
	{
		if (end == 0 || str[end - 1] != 'f')
			return (false);
		--end;
	}
	dot = str.find('.', begin);
	if (dot == std::string::npos || dot >= end
		|| str.find('.', dot + 1) != std::string::npos)
		return (false);
	hasDigitsBefore = isDigits(str, begin, dot);
	hasDigitsAfter = isDigits(str, dot + 1, end);
	return (hasDigitsBefore || hasDigitsAfter);
}

eType getType(const std::string &str)
{
	if (str.empty())
		return UNKNOWN;
	if (isSpecial(str))
		return SPECIAL;
	if (str.length() == 1)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[0])))
			return CHAR;
		else
			return INT;
	}
	if (isInteger(str))
		return INT;
	if (isDecimal(str, true))
		return FLOAT;
	if (isDecimal(str, false))
		return DOUBLE;
	return UNKNOWN;
}
