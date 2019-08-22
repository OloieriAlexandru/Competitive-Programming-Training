#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 100005
#define inf 1000000001
using namespace std;
bool bakery[nmax];
int n, m, k, x, y, c, ans = inf;
vector<pii>g[nmax];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=m;++i)
    {
        scanf("%d %d %d",&x,&y,&c);
        g[x].pb(mp(y,c));
        g[y].pb(mp(x,c));
    }
    for (int i=1;i<=k;++i)
    {
        scanf("%d",&x);
        bakery[x] = true;
    }
    for (int i=1;i<=n;++i)
    {
        if (bakery[i]) continue;
        for (auto x:g[i])
            if (bakery[x.first])
                ans = min(ans, x.second);
    }
    if (ans == inf)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
    return 0;
}
