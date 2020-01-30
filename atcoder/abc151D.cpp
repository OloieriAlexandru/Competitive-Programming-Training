#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 22
#define inf 999999999
#define lld long long
#define ld long double
using namespace std;
int n, m;
char mat[nmax][nmax];
int d1[nmax][nmax], d2[nmax][nmax];
bool u1[nmax][nmax], u2[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}
void lee(int x, int y, int d[nmax][nmax], bool u[nmax][nmax]){
    queue<pii>q;
    d[x][y] = 0;
    q.push(mp(x,y));
    u[x][y] = true;
    while (!q.empty()){
        auto act = q.front();
        q.pop();
        int i = act.first;
        int j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (u[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (mat[i+dl[k]][j+dc[k]] != '.'){
                continue;
            }
            d[i+dl[k]][j+dc[k]]=d[i][j]+1;
            u[i+dl[k]][j+dc[k]]=true;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>mat[i][j];
        }
    }
    int ans = 0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (mat[i][j] != '.'){
                continue;
            }
            memset(d1,0,sizeof(d1));
            memset(u1,0,sizeof(u1));
            lee(i,j,d1,u1);
            for (int i=1;i<=n;++i){
                for (int j=1;j<=m;++j){
                    ans = max(ans, d1[i][j]);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
