#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << "Lumberjacks:\n";
    while (t--)
    {
        int L[10];
        bool flag1, flag2;
        for (int i = 0; i < 10; ++i)
            cin >> L[i];
            
        flag1 = flag2 = true;    
        for (int i = 1; i < 10; ++i)
        {
            if (L[i - 1] > L[i])
                flag1 = false;
            else if (L[i - 1] < L[i])
                flag2 = false;
        }
        
        if (flag1 || flag2)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }    
}
