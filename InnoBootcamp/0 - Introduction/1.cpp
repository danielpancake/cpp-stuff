/*
 * Calculate the area of a triangle from its sides
*/

#include <iostream>
#include <cmath>

int main() {
    double a, b, c;

    std::cout << "Enter lengths of trinagle sides:\n";
    std::cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0) {
        if ( (a <= b + c) && (b <= a + c) && (c <= a + b) ) {
            double p = (a + b + c) / 2;
            double S = sqrt(p * (p - a) * (p - b) * (p - c));

            std::cout << "Triangle exists. Area of the triangle is " << S; 
        } else {
            std::cout << "Wrong values";
        }
    } else {
        std::cout << "Wrong values";
    }
}