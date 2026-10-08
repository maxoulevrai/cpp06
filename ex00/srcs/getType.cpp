/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:22:56 by codespace         #+#    #+#             */
/*   Updated: 2026/10/05 19:03:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

eType	getType(const std::string &str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	else if (str.find('.') != std::string::npos)
		return FLOAT;
	else if (str.find('f') != std::string::npos)
		return DOUBLE;
	else
		return INT;
}

