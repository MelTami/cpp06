/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:53:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/21 20:22:24 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <limits>
# include <cfloat>
# include <string.h>

// COLORS
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"

// ENUMERATORS
enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

// GLOBAL VARIABLES
const std::string _pseudo_literals[] = {"nan", "inf"};

class ScalarConverter
{
    private:
        /* data */
    public:
        ScalarConverter(); //Constructor
        ScalarConverter(const ScalarConverter &src); // Copy constructor
        ~ScalarConverter(); //Desctructor
        ScalarConverter	&operator=(const ScalarConverter &src);

        static int getType(const std::string &literal);
        // Member functions for checking
        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        // Member functions for converting
        static void toChar(const std::string &literal);
        static void toInt(const std::string &literal);
        static void toFloat(const std::string &literal);
        static void toDouble(const std::string &literal);

        static void convert(const std::string &literal);
        // Exceptions
        class InvalidLiteralException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        class NonDisplayableException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
};

#endif