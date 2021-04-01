#define PI 3.14159265358979323846
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
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
    double Perimeter() const;
    double Square() const;
    double * Angle(double* angl)const;
public:
    Triangle();
    Triangle(double sides[]);
    Triangle(Triangle* triangle);
    ~Triangle();
    
    void Set(double sides[]);
    double Get_A() const;
    double Get_B() const;
    double Get_C() const;
    double Get_Perimeter() const;
    double Get_Square() const;
    double *Get_Angle() const;
    bool Istriangle() const;
    void operator*(double k);
    string toString() const;
    friend Triangle operator*(double k, Triangle tr);
    friend ostream & operator<<(ostream & os, const Triangle & tr);
};