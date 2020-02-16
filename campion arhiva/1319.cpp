#include <bits/stdc++.h>
#define nmax 505
#define pii pair<int,int>
#define mp make_pair
#define inf 999999999
using namespace std;
int n, m, ans1, ans2;
char s[nmax][nmax];
pii ans[nmax][nmax];
bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
void lee(int l, int c){
    queue<pii>q;
    pii act;
    int i, j, ii, jj, n1, n2;
    q.push(mp(l,c));
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            ans[i][j].first = ans[i][j].second = inf;
        }
    }
    ans[l][c].first = ans[l][c].second = 0;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            ii = i+dl[k];
            jj = j+dc[k];
            n2 = ans[i][j].second + 1;
            n1 = ans[i][j].first;
            if (s[ii][jj] != s[i][j]){
                ++n1;
            }
            if (n1 < ans[ii][jj].first || (n1 == ans[ii][jj].first && n2 < ans[ii][jj].second)){
                ans[ii][jj].first = n1;
                ans[ii][jj].second = n2;
                q.push(mp(ii,jj));
            }
        }
    }
}
int main()
{
    freopen("pixy.in","r",stdin);
    freopen("pixy.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%s",(s[i]+1));
    }
    lee(1,1);
    printf("%d\n%d\n", ans[n][m].first, ans[n][m].second);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
