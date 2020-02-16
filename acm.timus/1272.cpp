#include <bits/stdc++.h>
#define nmax 10005
#define pb push_back
using namespace std;
vector<int>g[nmax];
int n, m, k;
int x, y, cc;
bool uz[nmax];
void dfs(int k){
    uz[k] = true;
    for (auto x:g[k]){
        if (uz[x]){
            continue;
        }
        dfs(x);
    }
}
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1;i<=k;++i){
        cin>>x>>y;
    }
    for (int i=1;i<=n;++i){
        if (uz[i]){
            continue;
        }
        dfs(i);
        ++cc;
    }
    cout<<(cc-1)<<'\n';
    return 0;
}
