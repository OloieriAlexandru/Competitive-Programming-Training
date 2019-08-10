#include <bits/stdc++.h>
using namespace std;
int n, fv[4], x, ans = 1000001;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        ++fv[x];
    }
    for (int i=1;i<=3;++i)
        ans = min(ans, n - fv[i]);
    cout<<ans<<'\n';
    return 0;
}
