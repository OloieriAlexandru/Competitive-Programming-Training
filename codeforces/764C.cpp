#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
vector<pair<int,int>>edges;
vector<int>g[nmax];
int n, x, y, c[nmax];
int v1, v2, cnt, col, coll;
bool alrd[nmax];
void dfs(int k, int lst, int col)
{
    ++cnt;
    if (c[k] == col) ++coll;
    for (auto x:g[k])
    {
        if (x == lst) continue;
        dfs(x, k, col);
    }
}
bool check(int node)
{
    bool ok = true;
    for (auto x:g[node])
    {
        cnt = 0, col = c[x];
        coll = 0;
        dfs(x, node, col);
        if (cnt != coll)
        {
            ok = false;
            break;
        }
    }
    return ok;
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d",&x,&y);
        edges.push_back(make_pair(x,y));
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i=1; i<=n; ++i)
        scanf("%d",&c[i]);
    bool found = false;
    int indx;
    for (int i=0; i<edges.size(); ++i)
    {
        if (c[edges[i].first] != c[edges[i].second])
        {
            found = true;
            indx = i;
            break;
        }
    }
    if (!found)
    {
        cout<<"YES\n1\n";
        return 0;
    }
    if (check(edges[indx].first))
    {
        cout<<"YES\n";
        cout<<edges[indx].first<<'\n';
        return 0;
    }
    if (check(edges[indx].second))
    {
        cout<<"YES\n";
        cout<<edges[indx].second<<'\n';
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
