#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s[6] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
    int B[3];
    int G[3];
    int C[3];
    while (cin >> B[0] >> G[0] >> C[0]
               >> B[1] >> G[1] >> C[1]
               >> B[2] >> G[2] >> C[2])
    {
        int b = B[0] + B[1] + B[2];
        int g = G[0] + G[1] + G[2];
        int c = C[0] + C[1] + C[2];
        int A[6] = {b - B[0] + g - G[2] + c - C[1],
                    b - B[0] + g - G[1] + c - C[2],
                    b - B[1] + g - G[2] + c - C[0],
                    b - B[2] + g - G[1] + c - C[0],
                    b - B[1] + g - G[0] + c - C[2],
                    b - B[2] + g - G[0] + c - C[1]};
        int min = A[0];
        int ind = 0;
        for (int i = 1; i < 6; ++i)
        {
            if (min > A[i])
            {
                ind = i;
                min = A[i];
            }
        }
                
        cout << s[ind] << ' ' << min << '\n';
    }
}
