#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
int fv[nmax], n, k, x, mod20, mod21, ans;
int main()
{
    cin>>n>>k;
    k = (n + 1) / 2;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        ++fv[x];
    }
    for (int i=1;i<=1000;++i)
    {
        mod20 += fv[i]/2;
        mod21 += fv[i]%2;
    }
    while (mod20 > 0)
    {
        if (!k) break;
        --mod20, --k, ans += 2;
    }
    while (mod21)
    {
        if (!k) break;
        --mod21, --k, ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
