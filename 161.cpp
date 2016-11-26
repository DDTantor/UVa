#include <iostream>
#include <vector>
#include <cstdint>
#include <bitset> 

using namespace std;

int main()
{
    int a;
    while (cin >> a, a)
    {
        vector<int> A;
        int time = 90;
        bitset<100> mask = 0;
        A.push_back(a);
        if (a < time)
            time = a;
        while (cin >> a, a)
        {
            if (time > a)
                time = a;
            A.push_back(a);
        }
        do
        {
            time++;
            for (int i = 0; i < A.size(); ++i)
            {
                if (time % (2 * A[i]) >= A[i] - 5)
                    mask[i] = 1;
                else
                    mask[i] = 0;
            }        
        }while (time < 5 * 3600 && mask.count());
        if (!mask.count())
            printf("%02d:%02d:%02d\n", time / 3600, (time % 3600) / 60, time % 60); 
        else
            printf("Signals fail to synchronise in 5 hours\n");
    }
    
}
