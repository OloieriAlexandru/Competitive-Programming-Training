#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&k);
        if (n == k || n == 1 || n == 2)
        {
            cout<<"Alice\n";
            continue;
        }
        if (k % 3)
        {
            if (!(n%3))
            {
                cout<<"Bob\n";
                continue;
            }
            cout<<"Alice\n";
            continue;
        }
        if ((n % (k+1))%3 == 0 && n % (k+1)!=k)
        {
            cout<<"Bob\n";
            continue;
        }
        cout<<"Alice\n";
        continue;
    }
    return 0;
}
