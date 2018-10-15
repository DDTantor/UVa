#include <iostream>
#include <cstring>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string s;
int A[3][3], cs = 1;

int main()
{
    while (getline(cin, s))
    {
        
        memset(A, 0, sizeof(A));
        for (char c : s)
        {
            int x = (c - 'a') / 3, y = (c - 'a') % 3;
            A[x][y] = (A[x][y] + 1) % 10;
            for (int k = 0; k < 4; ++k)
            {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3)
                    A[xx][yy] = (A[xx][yy] + 1) % 10;
            }
        }

        cout << "Case #" << cs++ << ":\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (j)
                    cout << ' ';

                cout << A[i][j];
            }

            cout << '\n';
        }
    }
}
