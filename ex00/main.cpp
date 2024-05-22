/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:32 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/21 20:19:16 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char *argv[]){

    if (argc != 2) {
        std::cout << "Usage: ./Converter \"<literal>\"" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}