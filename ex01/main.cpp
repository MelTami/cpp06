/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:19:23 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 01:26:36 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        cerr << RED << "serializer: error: command-line arguments aren't supported" << '\n';
        return EXIT_FAILURE;
    }

    data_t foo;
    uintptr_t reinterpreted;

    foo.dummy_str = std::string("test");
    reinterpreted = Serialization::serialize(&foo);

    cout << CYAN << "OG foo (Data) Address = " << RESET << &foo << endl
         << BLUE << "dummy_str value = " << RESET << foo.dummy_str << endl;

    cout << endl;

    cout << YELLOW << "Reinterpreted foo value = " << RESET << reinterpreted << endl;

    cout << endl;

    data_t *deserialized;

    deserialized = Serialization::deserialize(reinterpreted);

    cout << GREEN << "Deserialized Address = " << RESET << deserialized << endl
         << MAGENTA << "dummy_str value = " << RESET << deserialized->dummy_str << endl;

    return EXIT_SUCCESS;
}
