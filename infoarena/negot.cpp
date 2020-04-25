#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
#define nmax2 40005
using namespace std;
int fv[nmax], x, n, m, k, nr;
int lft[nmax2], rgh[nmax][33];
bool uz[nmax2];
vector<int>g[nmax2];
bool cup(int node){
    if (uz[node]){
        return false;
    }
    uz[node] = true;
    int nd;
    for (int i=0;i<g[node].size();++i){
        nd = g[node][i];
        if (fv[nd] == k){
            continue;
        }
        lft[node] = nd;
        rgh[nd][fv[nd]++] = node;
        return true;
    }
    for (int i=0;i<g[node].size();++i){
        int nd = g[node][i];
        for (int j=0;j<k;++j){
            if (cup(rgh[nd][j])){
                lft[node] = nd;
                rgh[nd][j] = node;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    freopen("negot.in","r",stdin);
    freopen("negot.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;++i){
        scanf("%d",&nr);
        for (int j=1;j<=nr;++j){
            scanf("%d",&x);
            g[x].pb(i);
        }
    }
    bool ok = true;
    while (ok){
        ok = false;
        memset(uz, 0, sizeof(uz));
        for (int i=1;i<=m;++i){
            if (!uz[i] && !lft[i]){
                if (cup(i)){
                    ok = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=m;++i){
        if (lft[i]){
            ++ans;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
