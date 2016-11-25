    #include <string>
    #include <iostream>

    using namespace std;

    int main()
    {
        int k, n;
        string K[100];
        while (cin >> k, k)
        {
            cin >> n;
            for (int i = 0; i < k; ++i)
                cin >> K[i];
            
            int c, r, cnt = 0;
            string s;
            for (int i = 0; i < n; ++i)
            {
                cin >> c >> r;
                int t = 0;
                for (int j = 0; j < c; ++j)
                {
                    bool flag = false;
                    cin >> s;
                    for (int l = 0; l < k; ++l)
                        if (s == K[l])
                            flag = true;
                    
                    if (flag)
                        t++;
                }
                if (t >= r)
                    cnt++;
            }
            
            if (cnt == n)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
