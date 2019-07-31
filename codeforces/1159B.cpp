#include <bits/stdc++.h>
#define nmax 300005
#define inf 1999999999
using namespace std;
int n, a[nmax], v1, v2, maxx, minn = inf, ans = inf;
vector<int>pozs;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        minn = min(minn, a[i]);
    }
    for (int x=1;x<=n;++x)
    {
        v1 = v2 = 0;
        if (x > 1)
            v1 = x - 1;
        if (x < n)
            v2 = n - x;
        maxx = max(v1, v2);
        if (v1 == v2)
        {
            minn = min(a[x], a[1]);
            ans = min(ans, minn/maxx);
            minn = min(a[x], a[n]);
            ans = min(ans, minn/maxx);
        }
        else
        if (v1 > v2)
        {
            minn = min(a[x], a[1]);
            ans = min(ans, minn/maxx);
        }
        else
        {
            minn = min(a[x], a[n]);
            ans = min(ans, minn/maxx);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
