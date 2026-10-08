/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:43:48 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 13:50:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>


enum eType {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	SPECIAL = 4,
	UNKNOWN = 5
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static const void convert(const std::string &str);
};

eType	getType(const std::string &str);
void	doConvert(std::string str, eType type);


#endif