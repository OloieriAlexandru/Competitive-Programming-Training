#include <bits/stdc++.h>
using namespace std;
int n, m, p1, p2, i1, i2, x, ans;
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        if (x % 2) ++i1; else ++p1;
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%d",&x);
        if (x % 2) ++i2; else ++p2;
    }
    ans += min(i1, p2);
    ans += min(i2, p1);
    cout<<ans<<'\n';
    return 0;
}
