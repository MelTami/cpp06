/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:25 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 12:46:16 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(Serialization const &src) { *this = src; }

Serialization::~Serialization() {}

Serialization &Serialization::operator=(Serialization const &src)
{
	if (this != &src)
	{
		*this = src;
		return(*this);
	}
    return (*this);
}

uintptr_t Serialization::serialize(Data *ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data *Serialization::deserialize(uintptr_t raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}
