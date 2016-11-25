#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    string s[2];
    while (getline(cin, s[0]))
    {
        getline(cin, s[1]);
        int cnt[2] = {0, 0};
        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < s[j].length(); ++i)
            {
                if (s[j][i] <= 'Z' && s[j][i] >= 'A')
                    cnt[j] += s[j][i] - 'A' + 1;
                if (s[j][i] <= 'z' && s[j][i] >= 'a')
                    cnt[j] += s[j][i] - 'a' + 1;
            }
        
        for (int i = 0; i < 2; ++i)
            while(cnt[i] >= 10)
                cnt[i] = cnt[i] / 10 + cnt[i] % 10;
            
        if (cnt[0] > cnt[1])
            swap(cnt[0], cnt[1]);
        
        double r = (cnt[1] == 0)? 0 : (double)cnt[0] / cnt[1] * 100.0;
        if (cnt[0] == 0 && cnt[1] == 0)
            printf("\n");
        else
            printf("%.2lf %\n", r);
    }
}
