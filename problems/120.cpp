#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int A[30];
    string s;
    while (getline(cin, s))
    {
        cout << s << '\n';
        istringstream iss(s);
        int n = 0, a;
        while (iss >> a)
            A[n++] = a;

        for (int i = n - 1; i >= 0; --i)
        {
            int M = 0, id = 0;
            for (int j = 0; j <= i; ++j)
                if (M <= A[j])
                    M = A[j], id = j;

            if (id != i)
            {
                if (id != 0)
                {
                    cout << n - id << ' ';
                    for (int j = 0; j <= id / 2; ++j)
                        swap(A[j], A[id - j]);
                }

                cout << n - i << ' ';
                for (int j = 0; j <= i / 2; ++j)
                    swap(A[j], A[i - j]);
            }
                
        }

        cout << "0\n";
    }
}
