#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
#define mp make_pair
using namespace std;
int n, a[nmax], h, root;
vector<int>g[nmax];
void dfs(int k, int lst, int hh){
    h = max(h, hh);
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        dfs(x, k, hh+1);
    }
}
int main()
{
    freopen("inaltime.in","r",stdin);
    freopen("inaltime.out","w",stdout);
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
    dfs(root, -1, 1);
    cout<<h<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
