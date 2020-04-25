#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
#define mp make_pair
using namespace std;
int n, a[nmax], root, maxx;
vector<int>g[nmax];
vector<int>ans;
void dfs(int k, int lst){
    if ((g[k].size() - (k == root ? 0 : 1))> maxx){
        maxx = (g[k].size() - (k == root ? 0 : 1));
        ans.clear();
        ans.pb(k);
    } else if ((g[k].size() - (k == root ? 0 : 1)) == maxx){
        ans.pb(k);
    }
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        dfs(x, k);
    }
}
int main()
{
    freopen("nrfii.in","r",stdin);
    freopen("nrfii.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]){
            g[i].pb(a[i]);
            g[a[i]].pb(i);
        } else {
            root = i;
        }
    }
    dfs(root, -1);
    sort(ans.begin(), ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
