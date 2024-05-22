/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:52:55 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/21 23:31:17 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// Default constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	// Copy constructor
    *this = src;
    return ;
}

ScalarConverter::~ScalarConverter()
{
	// Destructor
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(const std::string &literal){
    try {
        toChar(literal);
        toInt(literal);
        toFloat(literal);
        toDouble(literal);

        int type = getType(literal);
        switch (type)
        {
        case CHAR:
            toChar(literal);
            break;
        case INT:
            toInt(literal);
            break;
        case FLOAT:
            toFloat(literal);
            break;
        case DOUBLE:
            toDouble(literal);
            break;
        default:
            throw InvalidLiteralException();
            break;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return ;
}

// Get type
int ScalarConverter::getType(const std::string &literal) {
    if (isChar(literal))
        return (CHAR);
    if (isInt(literal))
        return (INT);
    if (isFloat(literal))
        return (FLOAT);
    if (isDouble(literal))
        return (DOUBLE);
    throw InvalidLiteralException();
}

// Member functions for checking
bool ScalarConverter::isChar(const std::string &literal) {
    size_t  len = literal.length();

    if (literal[0] > 31 && literal[0] < 127 && len == 1)
        return (true);
    return (false);
}

bool ScalarConverter::isInt(const std::string &literal) {
    size_t  len = literal.length();
    long    nb;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return (true);
    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            i++;
        if (!std::isdigit(literal[i]))
            return (false);
    }
    nb = std::strtol(literal.c_str(), NULL, 10);
    if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
        return (false);
    return (true);
}

bool ScalarConverter::isFloat(const std::string &literal) {
    size_t  len = literal.length();
    bool    dot = false;
    size_t  i = 0;
    double  nb;

    if (literal.substr(i, len) == "nanf")
        return (true);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inff")
        return (true);
    if (literal[len - 1] != 'f')
        return (false);
    for (; i < len - 1; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    if (!dot)
        return (false);
    nb = std::strtod(literal.c_str(), NULL);
    if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(const std::string &literal) {
    size_t  len = literal.length();
    size_t  i = 0;
    bool    dot = false;
    double  nb;

    if (literal.substr(i, len) == "nan")
        return (true);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inf")
        return (true);
    for (; i < len; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (literal[i] < '0' || literal[i] > '9') {
            return (false);
        }
    }
    if (!dot)
        return (false);
    nb = std::strtod(literal.c_str(), NULL);
    if (nb > std::numeric_limits<double>::max() || nb < -std::numeric_limits<double>::max())
        return (false);
    return (true);
}

// Member functions for converting
void ScalarConverter::toChar(const std::string &literal) {
    size_t  len = literal.length();

    std::cout << BLUE << "Char: " << RESET;
    try {
        if (len > 3 || (literal[1] <= 31 && literal[1] >= 127))
            throw NonDisplayableException();
        std::cout << "'" << static_cast<char>(literal[0]) << "'" << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return ;
}
void ScalarConverter::toInt(const std::string &literal) {
    int nb;

    std::cout << YELLOW << "Int: " << RESET;
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        nb = static_cast<int>(literal[0]);
    else {
        nb = std::atoi(literal.c_str());
    }
    std::cout << nb << std::endl;
    return ;
}
void ScalarConverter::toFloat(const std::string &literal) {
    float   nb;
    int     len = literal.length();
    int     sign = 1;
    int     i = 0;

    if (literal.substr(i, len) == "nanf")
        nb = std::numeric_limits<float>::quiet_NaN();
    else {
        if (literal[i] == '-' || literal[i] == '+') {
            if (literal[i] == '-')
                sign *= -1;
            i++;
        }
        if (literal.substr(i, len) == "inff")
            nb = sign * std::numeric_limits<float>::infinity();
        else
            nb = std::atof(literal.c_str());
    }
    std::cout << GREEN << "Float: " << RESET << nb << "f" << std::endl;
    return ;
}
void ScalarConverter::toDouble(const std::string &literal) {
    double  nb;
    int     len = literal.length();
    int     sign = 1;
    int     i = 0;

    if (literal.substr(i, len) == "nan")
        nb = std::numeric_limits<double>::quiet_NaN();
    else {
        if (literal[i] == '-' || literal[i] == '+') {
            if (literal[i] == '-')
                sign *= -1;
            i++;
        }
        if (literal.substr(i, len) == "inf")
            nb = sign * std::numeric_limits<double>::infinity();
        else
            nb = std::strtod(literal.c_str(), NULL);
    }
    std::cout << MAGENTA << "Double: " << RESET << nb << std::endl;
    return ;
}

// Exceptions
const char *ScalarConverter::InvalidLiteralException::what() const throw() {
    return (RED "Invalid literal" RESET);
}
const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return (RED "Non displayable" RESET);
}