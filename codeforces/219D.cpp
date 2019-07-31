#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
vector<pair<int,bool>>g[nmax];
int n, act;
vector<int>ans;
int dist[nmax], red[nmax], totalRed, x, y;
void dfs(int k, int lst, int r, int d)
{
    red[k] = r;
    dist[k] = d;
    for (auto x:g[k])
    {
        if (x.first == lst) continue;
        int add = 0;
        if (!x.second) add = 1, ++totalRed;
        dfs(x.first, k, r +add, d + 1);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(make_pair(y,1));
        g[y].push_back(make_pair(x,0));
    }
    dfs(1,-1,0,0);
    int minn = 999999999;
    for (int i=1;i<=n;++i)
    {
        act = totalRed - 2 * red[i] + dist[i];
        if (act == minn)
            ans.push_back(i);
        else
        if (act < minn)
        {
            minn = act;
            ans.clear();
            ans.push_back(i);
        }
    }
    cout<<minn<<'\n';
    for (auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
