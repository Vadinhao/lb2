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
    //
    double Perimeter() const;
    double Square() const;
    double AngleA() const;
    double AngleB() const;
    double AngleC() const;
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
    double Get_AngleA() const;
    double Get_AngleB() const;
    double Get_AngleC() const;
    bool Istriangle() const;
    Triangle operator*(double k);
    string toString() const;
    friend Triangle operator*(double k, Triangle tr);
    friend ostream & operator<<(ostream & os, const Triangle & tr);
    friend string to_string(const Triangle & tr);
};