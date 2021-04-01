#include "Header.h";

Triangle::Triangle()
{
    A = 0;
    B = 0;
    C = 0;
    perimeter = 0;
    square = 0;
    angle = new double[3]{0,0,0};
}

Triangle::Triangle(double* sides)
{
    A = sides[0];
    B = sides[1];
    C = sides[2];
    perimeter = Perimeter();
    square = Square();
    angle = new double[3];
    angle = Angle(angle);
}

Triangle::Triangle(Triangle* triangle)
{
    A = triangle->A;
    B = triangle->B;
    C = triangle->C;
    perimeter = triangle->perimeter;
    square = triangle->square;
    angle = new double[3];
    angle = triangle->angle;
}

Triangle::~Triangle()
{
    delete[] angle;
}

void Triangle::Set(double* sides)
{
    A = sides[0];
    B = sides[1];
    C = sides[2];
    perimeter = Perimeter();
    square = Square();
    angle = new double[3];
    angle = Angle(angle);
}

double Triangle::Get_A() const
{
    return A;
}

double Triangle::Get_B() const
{
    return B;
}

double Triangle::Get_C() const
{
    return C;
}

bool Triangle::IsTriangle() const
{
	return (A + B > C) && (B + C > A) && (C + A > B);
}

void Triangle::operator*(double k)
{
    A = A * k;
    B = B * k;
    C = C * k;
}

void Triangle::operator*(double k, const Triangle & tr)
{
    A = A * k;
    B = B * k;
    C = C * k;
}

string Triangle::toString()const
{
    string s1;
    s1 = "A: " + A + ", B: " + B + ", C: " + C +"\nPerimeter: " + perimeter + "\nSquare: " + square + "\nAngles(a,b,c): " + angle[0] + ", " + angle[1] +", "+ angle[2]; 
    return s1; 
}

ostream & operator<<(ostream & os, const Time & t)
{
    os << toString();
}