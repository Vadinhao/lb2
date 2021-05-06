#include "Header.h";

Triangle::Triangle()
{
    A = 0;
    B = 0;
    C = 0;
}

Triangle::Triangle(double sides[])
{
    A = sides[0];
    B = sides[1];
    C = sides[2];
}

Triangle::Triangle(Triangle* triangle)
{
    A = triangle->A;
    B = triangle->B;
    C = triangle->C;
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
    return this->Perimeter();
}

double Triangle::Get_Square() const
{
    return this->Square();
}

double Triangle::Get_AngleA() const
{
    return this->AngleA();
}

double Triangle::Get_AngleB() const
{
    return this->AngleB();
}

double Triangle::Get_AngleC() const
{
    return this->AngleC();
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
    ostr << "A: " << A << ", B: " << B << ", C: " << C << "\nPerimeter: " << this->Get_Perimeter() << "\nSquare: " << this->Get_Square() << "\nAngles(a,b,c): " << this->Get_AngleA() << ", " << this->Get_AngleB() << ", " << this->Get_AngleC();
    s1 = ostr.str();
    return s1; 
}

string to_string(const Triangle& tr) 
{
    return tr.toString();
}

ostream& operator<<(ostream& os, const Triangle& tr)
{
    os  << tr.toString();
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

double Triangle::AngleA() const
{
    return 180 * acos((this->B * (this->B) + this->C * (this->C) - this->A * (this->A)) / (2 * (this->B) * (this->C))) / PI;
}

double Triangle::AngleB() const
{
    return 180 * acos((this->C * (this->C) + this->A * (this->A) - this->B * (this->B)) / (2 * (this->C) * (this->A))) / PI;
}

double Triangle::AngleC() const
{
    return 180 * acos((this->A * (this->A) + this->B * (this->B) - this->C * (this->C)) / (2 * (this->A) * (this->B))) / PI;
}