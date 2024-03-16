/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:49:22 by thibault          #+#    #+#             */
/*   Updated: 2023/12/02 23:13:58 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:

    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int intValue);
    Fixed(const float floatValue);
    ~Fixed();

    Fixed& operator=(const Fixed &other);
    float toFloat() const;
    int toInt() const;

private:

    int _fixedPtVal;
    static const int _fracBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif