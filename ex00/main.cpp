/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:32 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 02:04:42 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED "Error: wrong number of arguments" << std::endl;
        std::cout << "Usage: ./convert [value]" RESET << std::endl;
        return (1);
    }
    ScalarConverter::converter(argv[1]);
    return (0);
}