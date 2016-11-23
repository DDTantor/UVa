#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    while(1)
    {
        vector<string> T(52);
        for (int j = 51 ; j >= 0; --j)
        {
            cin >> T[j];
            if (T[j] == "#")
                return 0;
        }
                
        vector<stack<string> > C(13); 
        for (int j = 0; j < 4; ++j)
            for (int i = 0; i < 13; ++i)
                C[i].push(T[13 * j + i]);
    
        string nums = "A23456789TJQK";
        string curr = C[12].top();
        C[12].pop();
        int cnt = 1;
        for (int i = 0; i < 51; ++i)
        {
            int next = nums.find(curr[0]);
            if (C[next].empty())
                break;
            cnt++;
            curr = C[next].top();
            C[next].pop();
        }
        if (cnt < 10)
            cout << "0" << cnt;
        else
            cout << cnt;
        cout << "," << curr << endl;
    }
    return 0;
}
