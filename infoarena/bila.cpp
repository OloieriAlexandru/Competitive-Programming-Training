#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 65005
#define nmax2 127
#define inf 999999999
using namespace std;
vector<pii>bl[nmax];
int ans1, ans2, mn, ch, ii, jj;
int a[nmax2][nmax2], cnt[nmax2][nmax2];
int n, m, x, maxx, l, c;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int main()
{
    freopen("bila.in","r",stdin);
    freopen("bila.out","w",stdout);

    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",&x);
            bl[x].pb(mp(i,j));
            maxx = max(maxx, x);
            a[i][j] = inf;
        }
    }
    for (int i=0;i<=n+1;++i){
        a[i][0] = a[i][m+1] = inf;
    }
    for (int i=0;i<=m+1;++i){
        a[0][i] = a[n+1][i] = inf;
    }
    for (int i=1;i<=maxx;++i){
        for (unsigned j=0;j<bl[i].size();++j){
            l = bl[i][j].first;
            c = bl[i][j].second;
            mn = inf;
            ch = 0;
            for (int k=0;k<4;++k){
                ii = l + dl[k];
                jj = c + dc[k];
                if (mn > a[ii][jj] && i > a[ii][jj]){
                    mn = a[ii][jj];
                    ch = cnt[ii][jj];
                }
            }
            a[l][c] = i;
            cnt[l][c] = ch + 1;
            if (cnt[l][c] > ans1){
                ans1 = cnt[l][c], ans2 = i;
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
