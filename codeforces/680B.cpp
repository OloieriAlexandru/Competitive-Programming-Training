#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, x, st, dr, a[nmax], ans;
int main()
{
    cin>>n>>x;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    st = dr = x;
    while (dr <= n || st >= 1)
    {
        if (st >= 1 && dr <=n && a[st] && a[dr])
        {
            if (st == dr)
                ++ans;
            else ans += 2;
        }
        else
        if (st >= 1 && a[st] && dr > n)
            ++ans;
        else
        if (dr <= n && a[dr] && st < 1)
            ++ans;
        --st, ++dr;
    }
    cout<<ans<<'\n';
    return 0;
}
