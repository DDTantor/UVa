#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string in, out;

void Solve(string s, string sol, string stack, string com, int n)
{
    if (n == 2 * in.size())
    {
        if (sol == out)
            cout << com << '\n';
        return; 
    }
    
    //push
    if (s.size() > 0)
        Solve(s.substr(1, s.size() - 1), sol, stack + s[0], com + (n == 0? "i" : " i"), n + 1);
    
    //pop
    if (stack.size() > 0 && stack[stack.size() - 1] == out[sol.size()])
        Solve(s, sol + stack[stack.size() - 1], stack.substr(0, stack.size() - 1), com + " o", n + 1);
    
}

int main()
{
    while (cin >> in >> out)
    {
        cout << "[\n";
        if (is_permutation(in.begin(), in.end(), out.begin()))
            Solve(in, "", "", "", 0);
        cout << "]\n";
    }
}
