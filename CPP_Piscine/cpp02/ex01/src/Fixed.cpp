/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:49:01 by thibault          #+#    #+#             */
/*   Updated: 2023/12/03 15:46:22 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixedPtVal(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPtVal(other._fixedPtVal) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPtVal = other._fixedPtVal;
    }
    return *this;
}

Fixed::Fixed(const int intValue) : _fixedPtVal(intValue << _fracBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : _fixedPtVal(roundf(floatValue * (1 << _fracBits))) {
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->_fixedPtVal) / (1 << _fracBits);
}

int Fixed::toInt() const {
    return this->_fixedPtVal >> _fracBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}