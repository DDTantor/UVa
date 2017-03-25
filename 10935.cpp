#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        deque<int> D;
        for (int i = 1; i <= n; ++i)
            D.push_back(i);
          
        cout << "Discarded cards:";    
        while (D.size() > 1)
        {
            if (D.size() != n)
                cout << ",";
            cout << ' ' << D.front(), D.pop_front(), D.push_back(D.front()), D.pop_front();
        }
        cout << "\nRemaining card: " << D.front() << '\n';
    }
}
