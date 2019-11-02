#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
using namespace std;
int n, m, k, s, x, y;
bool uz[nmax];
vector<int>ks[nmax];
vector<int>dist[nmax];
vector<int>g[nmax];
void bfs(int kv)
{
    queue<pair<int,int>>q;
    for (int i=1;i<=n;++i)
        uz[i] = false;
    for (auto x:ks[kv]){
        q.push(make_pair(0, x));
        uz[x] = true;
    }
    while (!q.empty()){
        auto act = q.front();
        q.pop();
        int d = act.first;
        int k = act.second;
        dist[k].push_back(d);
        for (auto x:g[k]){
            if (uz[x]) continue;
            uz[x] = true;
            q.push(make_pair(d+1,x));
        }
    }
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&s);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        ks[x].push_back(i);
    }
    for (int i=1;i<=m;++i)
    {
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1;i<=k;++i)
        bfs(i);
    for (int i=1;i<=n;++i)
    {
        long long ans = 0;
        sort(dist[i].begin(), dist[i].end());
        for (int j=0;j<s;++j){
            ans += dist[i][j];
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
    return 0;
}
