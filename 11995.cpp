#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        bool isPQ, isS, isQ;
        isPQ = isS = isQ = true;
        priority_queue<int> PQ;
        queue<int> Q;
        stack<int> S;
        int c, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> c >> x;
            if (c == 1)
                PQ.push(x), S.push(x), Q.push(x);
            else 
            {
                if (PQ.empty())
                    isPQ = isS = isQ = false;
                else
                {    
                    isPQ &= (PQ.top() == x); PQ.pop();
                    isS &= (S.top() == x); S.pop();
                    isQ &= (Q.front() == x); Q.pop();
                }
            }
        }
        if (isQ + isPQ + isS > 1)
            cout << "not sure\n";
        else if (isPQ)
            cout << "priority queue\n";
        else if (isQ)
            cout << "queue\n";
        else if (isS)
            cout << "stack\n";
        else
            cout << "impossible\n";
    }
}
