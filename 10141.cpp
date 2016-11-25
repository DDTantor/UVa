#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string x;
    int n, p, c = 1;
    while (cin >> n >> p, n || p)
    {
        cin.ignore();
        for (int i = 0; i < n; ++i)
            getline(cin, x);
        
        string bestbrand;
        double bestprice = 2000000000;
        int bestcnt = -1;
        
        for (int i = 0; i < p; ++i)
        {
            string brand;
            getline(cin, brand);
            double price;
            int cnt;
            cin >> price >> cnt;
            cin.ignore();
            for (int j = 0; j < cnt; ++j)
                getline(cin, x);
                
            if (cnt > bestcnt || (cnt == bestcnt && bestprice > price))
            {
                bestbrand = brand;
                bestprice = price;
                bestcnt = cnt;
            }
        }
        if (c > 1)
            cout << '\n';
        cout << "RFP #" << c++ << '\n' << bestbrand << '\n';
    }
}
