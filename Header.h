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
    double perimeter;
    double square;
    double* angle;
    void Perimeter();
    void Square();
    void Angle(double* angl);
public:
    Triangle();
    Triangle(double* sides);
    Triangle(Triangle* triangle);
    ~Triangle();
    
    void Set(double sides);
    double Get_A() const;
    double Get_B() const;
    double Get_C() const;
    bool Istriangle() const;
    void operator*(double k);
    friend void operator*(double k, const Triangle & tr);
    string toString() const;
    friend ostram & operator<<(ostream & os, const & triangle);
};