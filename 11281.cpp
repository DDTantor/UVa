#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;

double Area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    int m, n;
    double R[100];
    char C = 'A';
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> R[i];
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        double a, b, c;
        cin >> a >> b >> c;
        cout << "Peg " << C++ << " will ";
        vi Fits;
        double r;
        if (a * a > c * c + b * b) r = a / 2;
        else if (b * b > c * c + a * a) r = b / 2;
        else if (c * c > a * a + b * b) r = c / 2;
        else r = a * b * c / (4.0 * Area(a, b, c));
        for (int j = 0; j < m; ++j)
        {    
            if (R[j] >= 2 *r)
            {
                Fits.push_back(j + 1);
            }
        }
        if (Fits.empty())
            cout << "not fit into any holes\n";
        else
        {
            cout << "fit into hole(s): ";
            for (int i = 0; i < Fits.size(); ++i)
            {
                if (i)
                    cout << ' ';
                
                cout << Fits[i];
            }
            cout << '\n';
        }
    }
}
