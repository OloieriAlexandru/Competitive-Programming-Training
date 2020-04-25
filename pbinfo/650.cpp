#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
#define mp make_pair
using namespace std;
int n, a[nmax], root, k;
vector<int>g[nmax];
vector<int>ans;
void dfs(int k, int lst, int hh){
    if (hh == ::k){
        ans.pb(k);
    }
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        dfs(x, k, hh+1);
    }
}
int main()
{
    freopen("knivel.in","r",stdin);
    freopen("knivel.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]){
            g[i].pb(a[i]);
            g[a[i]].pb(i);
        } else {
            root = i;
        }
    }
    dfs(root, -1, 1);
    sort(ans.begin(), ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
