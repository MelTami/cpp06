/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:52:55 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 02:04:10 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const std::string ScalarConverter::_pseudoLiterals[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    if (this != &src)
    {
        _strLiteral = src._strLiteral;
        _typeLiteral = src._typeLiteral;
        return (*this);
    }
    return (*this);
}

void ScalarConverter::converter(std::string str)
{
    if (str.empty())
    {
        std::cout << RED << "Error: empty string" << RESET << std::endl;
        return;
    }
    _strLiteral = str;
    if (defineType(str))
        return;
    switch (_typeLiteral)
    {
    case PSEUDO:
        printPseudo();
        break;
    case CHAR:
        convertChar();
        break;
    case INT:
        convertInt();
        break;
    case FLOAT:
        convertFloat();
        break;
    case DOUBLE:
        convertDouble();
        break;
    default:
        break;
    }
}

bool ScalarConverter::defineType(std::string str)
{
    int i = 0;
    int j = 0;

    while (i < 6)
    {
        if (str == _pseudoLiterals[i])
        {
            _typeLiteral = PSEUDO;
            return false;
        }
        i++;
    }
    if (str.length() == 1 && !isdigit(str[0]))
    {
        _typeLiteral = CHAR;
        return false;
    }
    if (str[0] == '+' || str[0] == '-')
        j++;
    if (checkInt(str, j))
        return true;
    return false;
}

bool ScalarConverter::checkInt(std::string str, int &j)
{
    int dot = 0;

    while (j < (int)str.length())
    {
        if (str[j] == '.')
            dot++;
        if (dot > 1 || (!isdigit(str[j]) && str[j] != '.' && (j != (int)str.length() - 1 || str[j] != 'f')))
        {
            std::cout << RED << "Error: invalid parameter" << RESET << std::endl;
            return true;
        }
        j++;
    }
    if (dot == 0)
    {
        if (str[str.length() - 1] == 'f')
        {
            std::cout << RED << "Error: invalid parameter" << RESET << std::endl;
            return true;
        }
        else
            _typeLiteral = INT;
    }
    else if (dot == 1)
        _typeLiteral = (str[str.length() - 1] == 'f') ? FLOAT : DOUBLE;
    return false;
}


void ScalarConverter::printPseudo()
{
    std::cout << YELLOW << "char: impossible" << RESET << std::endl;
    std::cout << YELLOW << "int: impossible" << RESET << std::endl;
    if (_strLiteral == "nanf" || _strLiteral == "nan")
    {
        std::cout << BLUE << "float: nanf" << RESET << std::endl;
        std::cout << MAGENTA << "double: nan" << RESET << std::endl;
    }
    else if (_strLiteral == "+inff" || _strLiteral == "+inf")
    {
        std::cout << BLUE << "float: +inff" << RESET << std::endl;
        std::cout << MAGENTA << "double: +inf" << RESET << std::endl;
    }
    else if (_strLiteral == "-inff" || _strLiteral == "-inf")
    {
        std::cout << BLUE << "float: -inff" << RESET << std::endl;
        std::cout << MAGENTA << "double: -inf" << RESET << std::endl;
    }
}

void ScalarConverter::convertChar()
{
    char c = _strLiteral[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertInt()
{
    int i = atoi(_strLiteral.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertFloat()
{
    float f = strtof(_strLiteral.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertDouble()
{
    double d = strtod(_strLiteral.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::printChar(char c)
{
    // CHAR_MIN is -128 and CHAR_MAX is 127
    if (atol(_strLiteral.c_str()) < CHAR_MIN || atol(_strLiteral.c_str()) > CHAR_MAX)
        std::cout << YELLOW << "char: impossible" << RESET << std::endl;
    else if (!isprint(c))
        std::cout << YELLOW << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;
}

void ScalarConverter::printInt(int i)
{
    // INT_MIN is -2147483648 and INT_MAX is 2147483647
    if (atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX)
        std::cout << YELLOW << "int: impossible" << RESET << std::endl;
    else
        std::cout << CYAN << "int: " << i << RESET << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    if ((atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX) 
        && (_typeLiteral == INT))
        std::cout << YELLOW << "float: impossible" << RESET << std::endl;
    else
        std::cout << BLUE << "float: " << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    if ((atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX) 
        && (_typeLiteral == INT))
        std::cout << YELLOW << "double: impossible" << RESET << std::endl;
    else
        std::cout << MAGENTA << "double: " << std::fixed << std::setprecision(1) << d << RESET << std::endl;
}

std::string ScalarConverter::_strLiteral = "";
int ScalarConverter::_typeLiteral = 0;