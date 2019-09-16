#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
using namespace std;
int n, k, cc, x, y, ans;
vector<int>g[nmax];
bool uz[nmax];
void dfs(int k)
{
    ++cc;
    uz[k] = true;
    for (auto x:g[k])
        if (!uz[x])
            dfs(x);
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=k;++i)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1;i<=n;++i)
    {
        if (uz[i]) continue;
        cc = 0;
        dfs(i);
        ans += cc-1;
    }
    cout<<k-ans<<'\n';
    return 0;
}
