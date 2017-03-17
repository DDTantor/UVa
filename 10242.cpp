#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct vec 
{
    double x, y;
    vec(){};
    vec(double x, double y) : x(x), y(y) {}
    vec operator +(const vec &other){ return vec(x + other.x, y + other.y);} 
    vec operator -(const vec &other){ return vec(x - other.x, y - other.y);}
    bool operator ==(const vec &other) const{ return (x == other.x && y == other.y);}
    friend istream& operator >> (istream& in, vec &other) {return in >> other.x >> other.y;}; 
};

int main()
{
    vec A, B, C, D, E;
    while (cin >> A >> B >> C >> D)
    {
        if (B == C)
            C = D;
        if (A == C)
            A = B, B = C, C = D;
        if (A == D)
            A = B, B = D;
            
        vec E = A - B + C;
        cout << fixed << setprecision(3) <<  E.x << ' ' << E.y << '\n';
    }
}
