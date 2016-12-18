#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define MP make_pair

int main()
{
    int k;
    while (cin >> k)
    {
        vii S;
        for (int y = k + 1; y <= 2 * k; ++y)
            if (!((y * k) % (y - k))) 
                S.push_back(MP((y * k) / (y - k), y));
        
        cout << S.size() << '\n';
        for (auto e : S)
            cout << "1/" << k << " = 1/" << e.first << " + 1/" << e.second << '\n'; 
    }
    
}
