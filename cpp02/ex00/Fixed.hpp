/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:20:04 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/21 22:20:05 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
private:
    int raw;
    static const int frac = 8;

public:
    Fixed();
    Fixed(const Fixed &num);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    
    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif