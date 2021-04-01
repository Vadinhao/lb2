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

Triangle::Triangle(double sides[])
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
    //
}

void Triangle::Set(double sides[])
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

double Triangle::Get_Perimeter() const 
{
    return perimeter;
}

double Triangle::Get_Square() const
{
    return square;
}

double* Triangle::Get_Angle() const
{
    return angle;
}

bool Triangle::Istriangle() const
{
	return (A + B > C) && (B + C > A) && (C + A > B);
}

Triangle Triangle::operator*(double k)
{
    Triangle temp(this);
    temp.A = temp.A * k;
    temp.B = temp.B * k;
    temp.C = temp.C * k;
    return temp;
}

Triangle operator*(double k, Triangle tr)
{
    double sides[3]{ tr.A * k, tr.B * k, tr.C * k };
    Triangle temp = new Triangle(sides);
    return temp;
}

string Triangle::toString() const
{
    string s1;
    std::ostringstream ostr;
    ostr << "A: " << A << ", B: " << B << ", C: " << C << "\nPerimeter: " << perimeter << "\nSquare: " << square << "\nAngles(a,b,c): " << angle[0] << ", " << angle[1] << ", " << angle[2];
    s1 = ostr.str();
    return s1; 
}

ostream& operator<<(ostream& os, const Triangle& tr)
{
    os << "A: " << tr.A << ", B: " << tr.B << ", C: " << tr.C << "\nPerimeter: " << tr.perimeter << "\nSquare: " << tr.square << "\nAngles(a,b,c): " << tr.angle[0] << ", " << tr.angle[1] << ", " << tr.angle[2];
    return os;
}

double Triangle::Perimeter() const
{
    return	this->A + this->B + this->C;
}

double Triangle::Square() const
{
    double p = Triangle::Perimeter() / 2;
    return sqrt(p * (p - this->A) * (p - this->B) * (p - this->C));
}

double* Triangle::Angle(double* angl)
{
    angl[0] = 180 * acos((this->B * (this->B) + this->C * (this->C) - this->A * (this->A)) / (2 * (this->B) * (this->C))) / PI;
    angl[1] = 180 * acos((this->C * (this->C) + this->A * (this->A) - this->B * (this->B)) / (2 * (this->C) * (this->A))) / PI;
    angl[2] = 180 * acos((this->A * (this->A) + this->B * (this->B) - this->C * (this->C)) / (2 * (this->A) * (this->B))) / PI;
    return angl;
}