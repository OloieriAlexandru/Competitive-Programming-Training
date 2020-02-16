#include <bits/stdc++.h>
#define nmax 255
#define inf 999999999
using namespace std;
int n, m, k, xs, ys, xf, yf;
int x, y, r, t, d;
struct ghz {
    int x, y, r, t, d, lmin, lmax, cmin, cmax;
    void compute(){
        lmin = max(1,x-r);
        lmax = min(n,x+r);
        cmin = max(1,y-r);
        cmax = min(m,y+r);
    }
};
vector<ghz> gz;
int ans[2][nmax][nmax], g[nmax][nmax];
const int maxT = 1000;
void checkThisGz(const ghz& gg, int t){
    if (!(t%(gg.d+gg.t)>=gg.t)){
        return;
    }
    for (int i=gg.lmin;i<=gg.lmax;++i){
        for (int j=gg.cmin;j<=gg.cmax;++j){
            g[i][j] = inf;
        }
    }
}
void checkGz(int t) {
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            g[i][j] = 0;
        }
    }
    for (unsigned int i=0;i<gz.size();++i){
        checkThisGz(gz[i], t);
    }
}
int getAns(){
    int old, now;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            ans[0][i][j] = inf;
        }
    }
    ans[0][xs][ys] = 1;
    checkGz(0);

    for (int tt=1;tt<=maxT;++tt){
        now = tt % 2;
        old = 1 - now;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                int minimum = inf;
                ans[now][i][j] = inf;
                if (j > 1 && g[i][j-1] != inf){
                    minimum = min(minimum, ans[old][i][j-1]);
                }
                if (i > 1 && g[i-1][j] != inf){
                    minimum = min(minimum, ans[old][i-1][j]);
                }
                if (i < n && g[i+1][j] != inf){
                    minimum = min(minimum, ans[old][i+1][j]);
                }
                if (minimum < inf){
                    ans[now][i][j] = minimum + 1;
                }
            }
        }
        checkGz(tt);

        if (ans[now][xf][yf] != inf && g[xf][yf] != inf){
            return ans[now][xf][yf];
        }
    }
    return 0;
}
int main()
{
    freopen("gheizere.in","r",stdin);
    freopen("gheizere.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d",&xs,&xf);
    ys = 1, yf = m;
    gz.resize(k);
    for (int i=0;i<k;++i){
        scanf("%d %d %d %d %d",&gz[i].x,&gz[i].y,&gz[i].r,&gz[i].t,&gz[i].d);
        gz[i].compute();
    }
    printf("%d\n", getAns());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
