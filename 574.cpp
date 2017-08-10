#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>

using namespace std;

typedef vector<int> vi;

int g, n, o;
vi nums;
set<string> comb;
bool picked[12];

void backtrack(int c, int sum)
{
    if (c == n && sum == g)
    {
        o++;
        string s = "";
        for (int i = 0; i < n; ++i)
            if (picked[i])
                s = s + to_string(nums[i]) + "+";
                 
        s.back() = '\n';
        if (comb.find(s) == comb.end())
        {
            cout << s;
            comb.insert(s);
        }
    }
    else if (c < n)
    {
        picked[c] = true, backtrack(c + 1, sum + nums[c]);
        picked[c] = false, backtrack(c + 1, sum);
    }
}

int main()
{
    while (cin >> g >> n, g || n)
    {
        cout << "Sums of " << g << ":\n";
        nums.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];

        comb.clear();
        sort(nums.begin(), nums.end(), greater<int>());
        o = 0;
        backtrack(0, 0);
        if (!o)
            cout << "NONE\n";
    }
}
