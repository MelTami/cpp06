/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:53:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 02:04:23 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <limits.h>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

// MACRO
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"

# define PSEUDO  0
# define CHAR    1
# define INT     2
# define FLOAT   3
# define DOUBLE  4


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter();

        ScalarConverter &operator=(ScalarConverter const &src);

        static const std::string _pseudoLiterals[6];
        static std::string _strLiteral;
        static int _typeLiteral;

        static bool defineType(std::string str);
        static bool checkInt(std::string str, int &j);

        static void convertChar();
        static void convertInt();
        static void convertFloat();
        static void convertDouble();

        static void printChar(char c);
        static void printInt(int i);
        static void printFloat(float f);
        static void printDouble(double d);
        static void printPseudo();
    public:
         static void converter(std::string strLiteral);
};

#endif
