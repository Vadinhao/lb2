#define PI 3.14159265358979323846
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

class Triangle 
{
private:
    double A;
    double B;
    double C;
    double Perimeter;
    double Square;
    double* Angle;

    void Perimeter();//2
    void Square();//3
    void Angle(double* angl);//4
    bool Istriangle() const;

public:
    Triangle();
    Triangle(double* sides);
    Triangle(Triangle* triangle);
    ~Triangle();

    void Set(double sides);
    double Get_A() const;
    double Get_B() const;
    double Get_C() const;

    Triangle operator*(double k) const;//1
    friend Triangle operator*(double k, const Triangle & tr);//1
    void add_el(int pos);
    void del_el(int pos);
    string * toString() const;
    friend ostram & operator<<(ostream & os, const & triangle);
};