#include <bits/stdc++.h>
#define nmax 825
#define pb push_back
using namespace std;

int n, m, x, y, maxx, node, ans, start;
char a[nmax][nmax];
vector<int>g[nmax*nmax];
bool uz[nmax*nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int pairToNode(int i, int j){
    return (i-1)*m+j;
}
void dfs1(int k, int depth){
    if (depth > maxx){
        maxx = depth;
        node = k;
    }
    uz[k] = true;
    for (auto x:g[k]){
        if (uz[x]){
            continue;
        }
        dfs1(x, depth+1);
    }
}
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            for (int k=0;k<4;++k){
                if (!interior(i+dl[k],j+dc[k])){
                    continue;
                }
                if (a[i+dl[k]][j+dc[k]] == '#'){
                    continue;
                }
                if (a[i][j] == '#'){
                    continue;
                }
                x = pairToNode(i, j);
                start = x;
                y = pairToNode(i+dl[k],j+dc[k]);
                g[x].pb(y);
            }
        }
    }
    dfs1(start, 0);
    maxx = 0;
    memset(uz,0,sizeof(uz));
    dfs1(node, 0);
    ans = maxx;
    cout<<ans<<'\n';
    return 0;
}
