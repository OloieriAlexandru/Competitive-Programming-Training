#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, p, act, a;
int main()
{
    cin>>n;
    for (int i=1;1;++i)
    {
        if ((1LL *i * (i+1)) / 2 > n) break;
        act = n - (1LL*i*(i+1))/2;
        if (act % i == 0)
            a = act/i+1, p = i;
    }
    cout<<a<<' '<<p<<'\n';
    return 0;
}
