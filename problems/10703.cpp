#include <cstring>
#include <iostream>

using namespace std;

int w, h, n, A[500][500];

int main()
{
    while (cin >> w >> h >> n, w || h || n)
    {
        memset(A, 0, sizeof(A));
        int x1, x2, y1, y2;
        for (int i = 0; i < n; ++i)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2)
                swap(x1, x2);

            if (y1 > y2)
                swap(y1, y2);
                    
            for (int x = x1 - 1; x < x2; ++x)
                for (int y = y1 - 1; y < y2; ++y)
                    A[y][x] = 1;
        }

        int res = h * w;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                res -= A[i][j];

        if (res == 1)
            cout << "There is one empty spot.\n";
        else if (res > 1)
            cout << "There are " << res << " empty spots.\n";
        else
            cout << "There is no empty spots.\n";
    }
}
