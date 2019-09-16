#include <bits/stdc++.h>
#define nmax 5005
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, ans[nmax], x, y;
bool cycle, uz[nmax], stck[nmax];
vector<pair<int,int>>g[nmax];
vector<pair<int,int>>edges;
void dfs(int k, int edge)
{
    stck[k] = true;
    uz[k] = true;
    for (auto x:g[k])
    {
        if (stck[x.first])
        {
            cycle = true;
            continue;
        }
        if (uz[x.first]) continue;
        dfs(x.first, x.second);
    }
    stck[k] = false;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y;
        g[x].pb(mp(y,i));
        edges.pb(mp(x,y));
    }
    for (int i=1;i<=n;++i)
    {
        if (uz[i]) continue;
        dfs(i, -1);
    }
    if (cycle)
        for (int i=0;i<m;++i)
            if (edges[i].first < edges[i].second)
                ans[i+1] = 1;
            else
                ans[i+1] = 2;
    else
        for (int i=1;i<=m;++i)
            ans[i] = 1;
    if (cycle)
        cout<<2<<'\n';
    else
        cout<<1<<'\n';
    for (int i=1; i<=m; ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}
