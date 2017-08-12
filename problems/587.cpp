#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

double dx[4] = {0.0, 1, 0.0, -1.0};
double dy[4] = {1.0, 0.0, -1.0, 0.0};

double x, y;
int c = 1;
string s1, S = "NESW";

void Add()
{
    int n = 0, i = 0;
    for (; isdigit(s1[i]); ++i)
        if (isdigit(s1[i]))
            n *= 10, n += s1[i] - '0'; 
            
    if (s1.size() - i == 1)
        x += n * dx[S.find(s1[i])], y += n * dy[S.find(s1[i])];
    else
        x += n / sqrt(2) * dx[S.find(s1[i + 1])], y += n / sqrt(2) * dy[S.find(s1[i])]; 
}

int main()
{
    string s;
    while (getline(cin, s, '.'), s[0] != 'E')
    {
        x = 0, y = 0;
        istringstream iss(s);
        while (getline(iss, s1, ','))
            Add();
        
        cout << "Map #" << c++;
        cout << fixed << setprecision(3) << "\nThe treasure is located at (" << x << ',' << y 
            << ").\nThe distance to the treasure is " << hypot((double)x, (double)y) << ".\n\n";
        cin.ignore();
    }
    
}
