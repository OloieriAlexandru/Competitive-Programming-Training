#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 105
using namespace std;
vector<pii>v;
bool uz[nmax];
int n, x, y, ans;
void dfs(int k)
{
    uz[k] = true;
    for (int i=0;i<n;++i)
    {
        if (i == k) continue;
        if (uz[i]) continue;
        if (v[i].first == v[k].first || v[i].second == v[k].second)
            dfs(i);
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    --ans;
    for (int i=0;i<n;++i)
    {
        if (uz[i]) continue;
        ++ans;
        dfs(i);
    }
    cout<<ans<<'\n';
    return 0;
}
