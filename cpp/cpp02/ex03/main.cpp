/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:09 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/03 18:52:09 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p(0, 3); // Point to test

    if (bsp(a, b, c, p)) {
        std::cout << "Point is inside the triangle!" << std::endl;
    } else {
        std::cout << "Point is outside the triangle!" << std::endl;
    }

    return 0;
}
