#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, m, d, inv[nmax], x, y, ans;
vector<int>g[nmax];
bool uz[nmax], infected[nmax];
int dist1[nmax], dist2[nmax];
int dmax, farthest, farthest2;
void dfs1(int k, int d)
{
    if (infected[k])
    {
        if (dmax < d)
            dmax = d, farthest = k;
    }
    uz[k] = true;
    for (auto x:g[k])
    {
        if (uz[x]) continue;
        dfs1(x, d+1);
    }
}
void dfs2(int k, int d)
{
    if (infected[k])
    {
        if (dmax < d)
            dmax = d, farthest2 = k;
    }
    uz[k] = true;
    for (auto x:g[k])
    {
        if (uz[x]) continue;
        dfs2(x, d+1);
    }
}
void bfs(int k, int dist[])
{
    queue<pair<int,int>>q;
    memset(uz, 0, sizeof(uz));
    uz[k] = true;
    q.push(make_pair(k, 0));
    while (!q.empty())
    {
        auto nw = q.front();
        q.pop();
        dist[nw.first] = nw.second;
        for (auto x:g[nw.first])
        {
            if (uz[x]) continue;
            uz[x] = true;
            q.push(make_pair(x, nw.second+1));
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&d);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d",&inv[i]);
        infected[inv[i]] = true;
    }
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dmax = 0;
    dfs1(1, 0);
    dmax = 0;
    memset(uz, 0, sizeof(uz));
    dfs2(farthest, 0);
    bfs(farthest, dist1);
    bfs(farthest2, dist2);
    for (int i=1;i<=n;++i)
        if (dist1[i] <= d && dist2[i] <= d) ++ans;
    printf("%d\n", ans);
    return 0;
}
