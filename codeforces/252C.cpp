#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
int a[nmax], n, st, d, dr, len;
lld ans;
int main()
{
    cin>>n>>d;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n < 3)
    {
        cout<<"0\n";
        return 0;
    }
    dr = 3;
    for (int i=1;i<=n-2;++i)
    {
        if (a[dr] - a[i] > d) continue;
        while (dr < n && a[dr+1] - a[i] <= d)
            ++dr;
        len = dr - i + 1;
        ans += (1LL*(len-2)*(len-1))/2;
    }
    cout<<ans<<'\n';
    return 0;
}
