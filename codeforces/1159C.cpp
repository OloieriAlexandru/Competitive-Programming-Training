#include <bits/stdc++.h>
#define nmax 100005
#define inf 999999999
using namespace std;
int minn, maxx, n, m, a[nmax], b[nmax];
long long ans, s1, s2;
int main()
{
    cin>>n>>m;
    minn = inf, maxx = 0;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        maxx = max(a[i], maxx);
        s1 += a[i];
    }
    sort(a+1,a+n+1,[](int a, int b) { return a>b; });
    for (int i=1; i<=m; ++i)
    {
        cin>>b[i];
        s2 += b[i];
        minn = min(b[i], minn);
    }
    sort(b+1,b+m+1,[](int a, int b) { return a>b; });
    if (minn < maxx)
    {
        cout<<"-1\n";
        return 0;
    }
    if (minn == maxx)
        ans = 1LL * m * s1 + s2 - 1LL * a[1] * m;
    else
        ans = 1LL * m * s1 + s2 - (m-1)*a[1] - a[2];
    cout<<ans<<'\n';
    return 0;
}
