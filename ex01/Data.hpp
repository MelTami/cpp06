/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:19:12 by mvavasso          #+#    #+#             */
/*   Updated: 2024/05/22 12:43:03 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data {
    Data(void);
    Data(std::string publicData, std::string privateData, int privateNumber);
    ~Data(void);
    Data(Data const &source);
    Data &operator=(Data const &source);

    std::string publicData;

    std::string getPrivateData(void) const;
    int         getPrivateNumber(void) const;
private:
    std::string _privateData;
    int         _privateNumber;
};

#endif
