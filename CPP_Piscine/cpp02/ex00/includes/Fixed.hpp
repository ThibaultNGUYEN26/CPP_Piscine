/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:13:27 by thibault          #+#    #+#             */
/*   Updated: 2023/11/30 20:37:21 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:

    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed& operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:

    int _fixedPtVal;
    static const int _fracBits = 8;

};

#endif