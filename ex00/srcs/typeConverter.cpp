/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:24:25 by codespace         #+#    #+#             */
/*   Updated: 2026/10/08 17:27:56 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	doCharConvert(std::string str,eType type) {
	if (type == CHAR)
		std::cout << "char: "<< str << std::endl;
}

void	doIntConvert(std::string str,eType type) {
	if (type == INT)

}

void	doFloatConvert(std::string str,eType type) {

}

void	doDoubleConvert(std::string str,eType type) {

}

void	hdlSpecial(std::string str) {
	if (str == "nan" || str == "nanf")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
	else if (str == "+inf" || str == "+inff")
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
	else
		return ;
}

void	doConvert(std::string &str, eType type) {
	if (type == SPECIAL) {
		hdlSpecial(str);
		return ;
	}
	doCharConvert(str, type);
	doIntConvert(str, type);
	doFloatConvert(str, type);
	doDoubleConvert(str, type);
}

