/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:53:04 by thibault          #+#    #+#             */
/*   Updated: 2023/12/03 15:46:56 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixedPtVal(0) {}

Fixed::Fixed(const Fixed &other) : _fixedPtVal(other._fixedPtVal) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int intValue) : _fixedPtVal(intValue << _fracBits) {}

Fixed::Fixed(const float floatValue) : _fixedPtVal(roundf(floatValue * (1 << _fracBits))) {}

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

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPtVal > other._fixedPtVal;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPtVal < other._fixedPtVal;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPtVal >= other._fixedPtVal;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPtVal <= other._fixedPtVal;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPtVal == other._fixedPtVal;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPtVal != other._fixedPtVal;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._fixedPtVal = this->_fixedPtVal + other._fixedPtVal;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._fixedPtVal = this->_fixedPtVal - other._fixedPtVal;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._fixedPtVal = (static_cast<int64_t>(this->_fixedPtVal) * other._fixedPtVal) >> _fracBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result._fixedPtVal = (static_cast<int64_t>(this->_fixedPtVal) << _fracBits) / other._fixedPtVal;
    return result;
}

Fixed& Fixed::operator++() {
    ++this->_fixedPtVal;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --this->_fixedPtVal;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}