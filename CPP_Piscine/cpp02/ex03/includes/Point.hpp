/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:47:29 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/14 10:49:33 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Point {

public:

    Point();
    Point(const int intValue);
    Point(const float floatValue);
    Point(const Point &other);
    ~Point();

    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed& operator++(); // pre-increment
    Fixed operator++(int); // post-increment
    Fixed& operator--(); // pre-decrement
    Fixed operator--(int); // post-decrement

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

private:

    int _fixedPtVal;
    static const int _fracBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);