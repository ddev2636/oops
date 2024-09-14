
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

// forward delaration
class Coordinates;

class Distance
{
public:
    double Sqrt(Coordinates, Coordinates);
};

class Coordinates
{
    double a, b;

public:
    void setNum(double x, double y)
    {
        a = x;
        b = y;
    }
    friend class Distance;
};

double Distance ::Sqrt(Coordinates o1, Coordinates o2)
{

    double sum = ((o2.a - o1.a) * (o2.a - o1.a) + (o2.b - o1.b) * (o2.b - o1.b));
    return sqrt(sum);
}

int main()
{
    Coordinates o1;
    Coordinates o2;
    o1.setNum(1, 0);
    o2.setNum(1, 0);

    Distance calc;

    double res = calc.Sqrt(o1, o2);
    cout << res << endl;

    return 0;
}