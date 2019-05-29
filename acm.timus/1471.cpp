#include <bits/stdc++.h>
#define nmax 50005
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
vector<pii>g[nmax];
int n, x, y, w;
int dist[nmax];
int eu[2*nmax];
int h[2*nmax], cnt, inalt = 1;
int frst[nmax];
int rmq[2*nmax][25], ans;
void dfs(int act, int last, int d)
{
    dist[act] = d;
    for (auto x:g[act])
    {
        if (x.first == last) continue;
        dfs(x.first, act, d + x.second);
    }
}
void euler(int act, int last)
{
    eu[++cnt] = act;
    frst[act] = cnt;
    h[cnt] = inalt;
    for (auto x:g[act])
    {
        if (x.first == last)continue;
        ++inalt;
        euler(x.first, act);
        --inalt;
        eu[++cnt] = act;
        h[cnt] = inalt;
    }
}
void rmqq()
{
    for (int i=1;i<=cnt;++i)
        rmq[i][0] = i;
    for (int j=1;(1<<j)<=cnt;++j)
        for (int i=1;i+(1<<j)-1<=cnt;++i)
            if (h[rmq[i][j-1]] <= h[rmq[i+(1<<(j-1))][j-1]])
                rmq[i][j] = rmq[i][j-1];
            else
                rmq[i][j] = rmq[i+(1<<(j-1))][j-1];
}
int l2(int x)
{
    if (x<=1) return 0;
    int ans = 0, act = 1;
    while (true)
    {
        if (act > x)
            return ans - 1;
        ++ans, act*=2;
    }
}
int lca(int x, int y)
{
    int lft = frst[x];
    int rgh = frst[y];
    if (lft > rgh) swap(lft, rgh);
    int dist = rgh - lft + 1;
    int lg2 = l2(dist);
    int add = dist - (1<<lg2);
    if (h[rmq[lft][lg2]] <= h[rmq[lft+add][lg2]])
        return eu[rmq[lft][lg2]];
    else
        return eu[rmq[lft+add][lg2]];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;++i)
    {
        scanf("%d %d %d",&x,&y,&w);
        ++x, ++y;
        g[x].pb(mp(y,w));
        g[y].pb(mp(x,w));
    }
    dfs(1,-1,0);
    euler(1,-1);
    rmqq();
    int q;
    scanf("%d",&q);
    for (int i=1;i<=q;++i)
    {
        scanf("%d %d",&x,&y);
        ++x, ++y;
        int nd = lca(x,y);
        ans = dist[x] + dist[y] - 2*dist[nd];
        printf("%d\n",ans);
    }
    return 0;
}