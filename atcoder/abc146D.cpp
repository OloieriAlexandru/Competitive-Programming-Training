#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 100005
using namespace std;
vector<pii>g[nmax];
int n, x, y, k;
int ans[nmax];
void dfs(int k, int lst, int color){
    int col = 1;
    for (auto x:g[k]){
        if (x.first == lst){
            continue;
        }
        if (col == color){
            ++col;
        }
        ans[x.second] = col;
        dfs(x.first, k, col);
        ++col;
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    for (int i=1;i<=n;++i){
        k = max(k, (int)g[i].size());
    }
    dfs(1, -1, 0);
    cout<<k<<'\n';
    for (int i=1;i<n;++i){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
