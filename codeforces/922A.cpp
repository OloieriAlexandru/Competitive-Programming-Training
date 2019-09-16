#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld x, y, a, b;
int main()
{
    cin>>x>>y;
    if (!y || y == 1 && x > 1)
    {
        cout<<"No\n";
        return 0;
    }
    b = y;
    a = y - 1;
    if ((x - a)% 2 == 0 && (x-a) >= 0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
