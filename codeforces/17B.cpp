#include <bits/stdc++.h>
#define nmax 1005
#define mp make_pair
#define inf 999999999
using namespace std;
unordered_map<int,int>g[nmax];
int n, m, a[nmax], x, y, cost;
int index, best[nmax], maxx = -1, add[nmax], minap[nmax];
bool checked[nmax];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
void dijkstra(int start)
{
    for (int i=1; i<=n; ++i)
        best[i] = inf, add[i] = inf;
    add[index] = 0;
    best[index] = 0;
    for (auto x:g[index])
    {
        pq.push(mp(x.second, x.first));
        best[x.first] = x.second;
        add[x.first] = x.second;
    }
    while (!pq.empty())
    {
        auto act = pq.top();
        pq.pop();
        x = act.first;
        y = act.second;
        if (checked[y])
            continue;
        checked[y] = true;
        for (auto node:g[y])
        {
            if (best[node.first] > best[y] + node.second)
            {
                best[node.first] = best[y] + node.second;
                add[node.first] = min(add[node.first], node.second);
                pq.push(mp(best[node.first], node.first));
            }
        }
    }
}
int main()
{
    cin>>n;
    bool ok = true;
    for (int i=1;i<=n;++i)
        minap[i] = inf;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        if (a[i] > maxx) maxx = a[i], index = i;
        else if (a[i] == maxx)
            ok = false;
    }
    if (!ok)
    {
        cout<<"-1\n";
        return 0;
    }
    cin>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y>>cost;
        minap[y] = min(minap[y], cost);
        if (g[x].count(y))
            g[x][y] = min(g[x][y], cost);
        else
            g[x][y] = cost;
    }
    dijkstra(index);
    long long ans = 0;
    minap[index] = 0;
    for (int i=1; i<=n; ++i)
    {
        if (best[i] == inf)
            ok = false;
        else
            ans += minap[i];
    }
    if (ok)
        cout<<ans<<'\n';
    else
        cout<<"-1\n";
    return 0;
}
