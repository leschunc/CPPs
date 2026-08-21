/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:20:20 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/21 22:20:21 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <cmath>
#include <iostream>

class Fixed
{
private:
    int raw;
    static const int frac = 8;

public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &num);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    Fixed &operator=(const Fixed &other);
    Fixed operator++(int n);
    Fixed operator--(int n);
    Fixed &operator--();
    Fixed &operator++();

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

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif