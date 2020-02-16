#include <bits/stdc++.h>
#define pb push_back
#define nmax 20005
using namespace std;
vector<int>g[nmax];
bool viz[nmax];
int n, m, x, y, cc[nmax], nrcc, actcc, ans, sum[nmax], req;
void dfs(int k){
    ++actcc;
    viz[k] = true;
    for (auto x:g[k]){
        if (!viz[x]){
            dfs(x);
        }
    }
}
int main()
{
    freopen("nunta.in","r",stdin);
    freopen("nunta.out","w",stdout);
    scanf("%d %d",&n,&m);
    req = n/2+1;
    for (int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1;i<=n;++i){
        if (viz[i]){
            continue;
        }
        actcc = 0;
        dfs(i);
        if (actcc > 1){
            cc[++nrcc] = actcc;
            sum[nrcc] = sum[nrcc-1] + actcc;
        }
    }
    for (int i=1;i<=nrcc;++i){
        for (int j=nrcc;j>=i;--j){
            if (sum[j]-sum[i-1]<req){
                break;
            }
            ++ans;
        }
    }
    printf("%d\n", nrcc);
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
