#include <bits/stdc++.h>
#define nmax 1000005
#define pb push_back
using namespace std;
int n, m, x, y, a[nmax], ans[nmax];
bool uz[nmax];
vector<int>g[nmax];
vector<int>el, pos;
void dfs(int k)
{
    uz[k] = true;
    el.pb(a[k]);
    pos.pb(k);
    for (auto x:g[k])
    {
        if (uz[x]) continue;
        dfs(x);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1; i<=n; ++i)
    {
        if (uz[i]) continue;
        el.clear();
        pos.clear();
        dfs(i);
        sort(pos.begin(), pos.end());
        sort(el.begin(), el.end(), [](int a,int b)
        {
            return a>b;
        });
        for (int i=0; i<pos.size(); ++i)
            ans[pos[i]] = el[i];
    }
    for (int i=1; i<=n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
