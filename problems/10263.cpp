#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

struct vec
{
    double x, y;
    vec(){}
    vec(double x, double y) : x(x), y(y) {}
    friend istream& operator >>(istream& in, vec& other){ return in >> other.x >> other.y;}
    friend ostream& operator <<(ostream& out, vec& other){ return out << other.x << '\n' << other.y << '\n';}
    vec operator -(const vec& other){ return vec (x - other.x, y - other.y);}
    vec operator +(const vec& other){ return vec (x + other.x, y + other.y);} 
}V[100];

vec Pr;

vec scale(vec v, double s)
{
    return vec(s * v.x, s * v.y);
}

double dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}

double snorm(vec a)
{
    return a.x * a.x + a.y * a.y;
}

double norm(vec a)
{
    return hypot(a.x, a.y);
}


double dist(vec p1, vec p2, vec M)
{
    double l = snorm(p2 - p1);
    double t = max(0.0, min(1.0, dot(M - p1, p2 - p1) / l));
    Pr = p1 + scale(p2 - p1, t);
    return hypot(M.x - Pr.x, M.y - Pr.y);  
}

int main()
{
    vec M;
    cout << fixed << setprecision(4);
    while (cin >> M)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n + 1; ++i)
            cin >> V[i];
            
        double min = INT_MAX;
        vec Mvec;
        
        for (int i = 1; i < n + 1; ++i)
        {
            double d = dist(V[i - 1], V[i], M);
            if (d < min)
                min = d, Mvec = Pr;
        }
        cout << Mvec;
    }
}
