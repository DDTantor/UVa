#include <iostream>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int t, board[5][5];
    cin >> t;
    while (t--)
    {
        int n, x, y, a;
        memset(board, 0, sizeof(board));
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> y >> x >> a;
            board[y][x] += a;
        }
        int m = INT_MAX;
        vi best(5), i(5);
        for (i[0] = 0; i[0] < 25; ++i[0])
        {
            for (i[1] = i[0] + 1; i[1] < 25; ++i[1])
            {
                for (i[2] = i[1] + 1; i[2] < 25; ++i[2])
                {
                    for (i[3] = i[2] + 1; i[3] < 25; ++i[3])
                    {
                        for (i[4] = i[3] + 1; i[4] < 25; ++i[4])
                        {
                            int sum = 0;
                            for (int k = 0; k < 25; ++k) 
                            {
                                x = k % 5;
                                y = k / 5;
                                int tmp = INT_MAX;
                                for (int j = 0; j < 5; ++j)
                                {
                                    int xi = i[j] % 5;
                                    int yi = i[j] / 5;
                                    tmp = min(tmp, board[y][x] * (abs(x - xi) + abs(y - yi)));
                                }
                                sum += tmp;
                            }
                            if (sum < m)
                                m = sum, best = i;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 5; ++j)
        {
            if (j)
                cout << ' ';
            cout << best[j];
        }
        cout << '\n';
    }
}
