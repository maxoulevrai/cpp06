/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:43:48 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 17:28:25 by maleca           ###   ########.fr       */
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
void	doCharConvert(std::string str,eType type);
void	doIntConvert(std::string str,eType type);
void	doFloatConvert(std::string str,eType type);
void	doDoubleConvert(std::string str,eType type);


#endif