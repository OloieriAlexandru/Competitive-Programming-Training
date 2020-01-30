#include <bits/stdc++.h>
#define nmax 100005
#define mp make_pair
#define pb push_back
using namespace std;
vector<int>g[nmax];
int x, y, n, curr, wh, las;
vector<pair<int,int>>ans;
void dfs(int k, int lst){
    int cn = 0;
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        ++cn;
        dfs(x, k);
    }
    if (!cn){
        curr = k;
    }
}
void dfs2(int k, int lst){
    las = k;
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        dfs2(x, k);
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int cnt = 0;
    for (int i=1;i<=n;++i){
        if (g[i].size() > 2 ){
            ++cnt;
            wh = i;
        }
    }
    if (cnt >= 2){
        cout<<"No\n";
        return 0;
    }
    if (cnt == 0){
        dfs2(1,-1);
        int ans1 = las;
        dfs2(las,-1);
        int ans2 = las;
        cout<<"Yes\n1\n";
        cout<<ans1<<' '<<ans2<<'\n';
        return 0;
    }
    for (auto x:g[wh]){
        dfs(x, wh);
        ans.push_back(make_pair(wh, curr));
    }
    cout<<"Yes\n"<<ans.size()<<'\n';
    for (auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }
    return 0;
}
