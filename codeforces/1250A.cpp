#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a[nmax], p[nmax], n, m, x, y;
pair<int,int>ans[nmax];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        a[i] = i;
        p[i] = i;
        ans[i].first = i, ans[i].second = i;
    }
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        if (p[x] == 1) continue;
        y = a[p[x]-1];
        --p[x];
        ++p[y];
        swap(a[p[x]],a[p[y]]);
        ans[x].first = min(ans[x].first, p[x]);
        ans[x].second = max(ans[x].second, p[x]);
        ans[y].first = min(ans[y].first, p[y]);
        ans[y].second = max(ans[y].second, p[y]);
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    return 0;
}
