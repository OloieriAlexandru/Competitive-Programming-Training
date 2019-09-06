#include <bits/stdc++.h>
#define nmax 1005
#define pb push_back
using namespace std;
vector<int>g[nmax];
int n, x, ans;
bool uz[nmax], ok;
void dfs(int k)
{
    if (ok) return;
    uz[k] = true;
    for (auto x:g[k])
    {
        if (uz[x])
        {
            ok = true, ans = x;
            return;
        }
        dfs(x);
    }
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        g[i].pb(x);
    }
    for (int i=1;i<=n;++i)
    {
        memset(uz, 0, sizeof(uz));
        ok = false;
        dfs(i);
        cout<<ans<<' ';
    }
    cout<<'\n';
    return 0;
}
