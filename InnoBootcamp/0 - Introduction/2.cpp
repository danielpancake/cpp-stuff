/*
 * Calculate the area of a triangle from its vertices
*/

#include <iostream>
#include <cmath>

struct Point2d {
    float X;
    float Y;
};

double length(Point2d p1, Point2d p2) {
    return sqrt( pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2) );
}

int main() {
    Point2d a, b, c;

    std::cout << "Enter coordinates (x, y) of 3 points:\n";
    std::cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;

    double l1, l2, l3;
    l1 = length(a, b);
    l2 = length(a, c); 
    l3 = length(b, c);

    double p = (l1 + l2 + l3) / 2;
    double S = sqrt( p * (p - l1) * (p - l2) * (p - l3) );

    std::cout << "Triangle exists. Area of the triangle is " << S; 
}