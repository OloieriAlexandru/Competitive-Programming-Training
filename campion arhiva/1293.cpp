#include <bits/stdc++.h>
#define mp make_pair
#define nmax 1005
#define inf 65000
using namespace std;
short int n, a[nmax][nmax], nw;
unsigned short xs, ys, xf, yf, ii, jj;
int ths;
unsigned short ans1[4][nmax][nmax], ans2[4][nmax][nmax];
int ans = inf, cntans, anss1 = inf, anss2;
bool inq[4][nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
struct e{
    unsigned short int v1, v2, v3;
};
void lee(unsigned short ans[4][nmax][nmax], unsigned short l, unsigned short c){
    queue<e>q;
    for (unsigned short int k=0;k<4;++k){
        inq[k][l][c] = true;
        ans[k][l][c] = 0;
        q.push({l,c,k});
    }
    e act;
    unsigned short i, j;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.v1, j = act.v2;
        inq[act.v3][i][j] = false;
        for (unsigned short int k=0;k<4;++k){
            ii = i+dl[k], jj = j+dc[k];
            if (a[ii][jj] == -1){
                continue;
            }
            nw = ans[act.v3][i][j] + (k == act.v3 ? 0 : 1);
            if (ans[k][ii][jj] > nw){
                ans[k][ii][jj] = nw;
                if (a[ii][jj]){
                    continue;
                }
                if (!inq[k][ii][jj]){
                    inq[k][ii][jj] = true;
                    q.push({ii,jj,k});
                }
            }
        }
    }
}
void check(int l, int c, int k1, int k2, int add){
    ths = min(ths, ans1[k1][l][c]+ans2[k2][l][c]+add);
}
int main()
{
    freopen("robot3.in","r",stdin);
    freopen("robot3.out","w",stdout);
    scanf("%hu",&n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            scanf("%hu",&a[i][j]);
            for (int k=0;k<4;++k){
                ans1[k][i][j] = ans2[k][i][j] = inf;
            }
        }
    }
    for (int i=0;i<=n+1;++i){
        a[i][0] = a[0][i] = a[i][n+1] = a[n+1][i] = -1;
    }
    scanf("%hu %hu %hu %hu",&xs,&ys,&xf,&yf);
    lee(ans1, xs, ys);
    lee(ans2, xf, yf);
    for (int i=0;i<4;++i){
        ans = min(ans, (int)ans1[i][xf][yf]);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (!a[i][j]){
                continue;
            }
            ++cntans;
            ths = inf;

            for (int k1=0;k1<4;++k1){
                for (int k2=0;k2<4;++k2){
                    if (i == j){
                        continue;
                    }
                    check(i,j,k1,k2,((k1%2)==(k2%2)?0:1));
                }
            }

            if (ths < anss1){
                anss1 = ths, anss2 = 1;
            } else if (ths == anss1){
                ++anss2;
            }
        }
    }
    if (ans < anss1){
        anss1 = ans, anss2 = cntans;
    } else if (ans == anss1){
        anss2 = max(cntans, anss2);
    }
    printf("%d %d %d\n", ans, anss1, anss2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
