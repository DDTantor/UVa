#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int Upiti[3001];

int main()
{
    string s;
    priority_queue<ii, vii, greater<ii> > PQ;
    while (cin >> s, s == "Register")
    {
        int id, t;
        cin >> id >> t;
        Upiti[id] = t;
        PQ.push(ii(t,id));
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int T = PQ.top().first;
        int ID = PQ.top().second;
        PQ.pop();
        cout << ID << endl;
        T += Upiti[ID];
        PQ.push(ii(T, ID));
    }
}
