#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
#define mp make_pair
using namespace std;
int n, a[nmax], root, cnt, x;
vector<int>g[nmax];
vector<int>ans[nmax];
vector<int>wh;
void dfs(int k, int lst){
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        ans[k].pb(x);
        dfs(x, k);
    }
}
int main()
{
    freopen("afisarefii.in","r",stdin);
    freopen("afisarefii.out","w",stdout);
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
    cin>>cnt;
    for (int i=1;i<=cnt;++i){
        cin>>x;
        wh.pb(x);
    }
    dfs(root, -1);
    for (auto node:wh){
        cout<<ans[node].size()<<' ';
        sort(ans[node].begin(), ans[node].end());
        for (auto nn:ans[node]){
            cout<<nn<<' ';
        }
        cout<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
