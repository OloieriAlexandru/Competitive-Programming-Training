#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 1005
#define mod 666013
using namespace std;
int n, m, xs, ys, xf, yf, dp[nmax][nmax];
int dl[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
bool interior(int i, int j){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void checkadd(int x, int y, int cx, int cy){
    if (interior(cx, cy)){
        dp[x][y] += dp[cx][cy];
        dp[x][y] %= mod;
    }
}
void depe(){
    int ls, cs, lf, cf, r = max(max(xs-1,ys-1),max(n-xs,m-ys));
    int i = xs, j = ys;
    for (int k=0;k<8;++k){
        if (!interior(i+dl[k],j+dc[k])){
            continue;
        }
        dp[i+dl[k]][j+dc[k]] = 1;
    }
    for (int t=2;t<=r;++t){
        // up
        ls = xs - t, lf = xs - t;
        cs = ys - t, cf = ys + t;
        if (interior(ls,cs)){
            dp[ls][cs] = 1;
        }
        if (interior(lf,cf)){
            dp[lf][cf] = 1;
        }
        if (interior(ls,cs+1)){
            checkadd(ls,cs+1,ls+1,cs+1);
            checkadd(ls,cs+1,ls+1,cs+2);
        }
        if (interior(lf,cf-1)){
            checkadd(lf,cf-1,lf+1,cf-1);
            checkadd(lf,cf-1,lf+1,cf-2);
        }
        for (int j=cs+2;j<=cf-2;++j){
            if (interior(ls,j)){
                checkadd(ls,j,ls+1,j-1);
                checkadd(ls,j,ls+1,j);
                checkadd(ls,j,ls+1,j+1);
            }
        }
        // right
        ls = lf, cs = cf;
        lf = xs + t, cf = ys + t;
        if (interior(lf,cf)){
            dp[lf][cf] = 1;
        }
        if (interior(ls+1,cs)){
            checkadd(ls+1,cs,ls+1,cs-1);
            checkadd(ls+1,cs,ls+2,cs-1);
        }
        if (interior(lf-1,cf)){
            checkadd(lf-1,cf,lf-1,cf-1);
            checkadd(lf-1,cf,lf-2,cf-1);
        }
        for (int i=ls+2;i<=lf-2;++i){
            if (interior(i, cs)){
                checkadd(i, cs, i-1, cs-1);
                checkadd(i, cs, i, cs-1);
                checkadd(i, cs, i+1, cs-1);
            }
        }
        // down
        ls = lf, cs = cf;
        lf = xs + t, cf = ys - t;
        if (interior(lf,cf)){
            dp[lf][cf] = 1;
        }
        if (interior(ls,cs-1)){
            checkadd(ls,cs-1,ls-1,cs-1);
            checkadd(ls,cs-1,ls-1,cs-2);
        }
        if (interior(lf,cf+1)){
            checkadd(lf,cf+1,lf-1,cf+1);
            checkadd(lf,cf+1,lf-1,cf+2);
        }
        for (int j=cs-2;j>=cf+2;--j){
            if (interior(ls, j)){
                checkadd(ls,j,ls-1,j-1);
                checkadd(ls,j,ls-1,j);
                checkadd(ls,j,ls-1,j+1);
            }
        }
        // left
        ls = lf, cs = cf;
        lf = xs - t, cf = ys - t;
        if (interior(ls-1,cs)){
            checkadd(ls-1,cs,ls-1,cs+1);
            checkadd(ls-1,cs,ls-2,cs+1);
        }
        if (interior(lf+1,cf)){
            checkadd(lf+1,cf,lf+1,cf+1);
            checkadd(lf+1,cf,lf+2,cf+1);
        }
        for (int i=ls-2;i>=lf+2;--i){
            if (interior(i, cs)){
                checkadd(i, cs, i+1, cs+1);
                checkadd(i, cs, i, cs+1);
                checkadd(i, cs, i-1, cs+1);
            }
        }
    }
}
int main()
{
    freopen("rege.in","r",stdin);
    freopen("rege.out","w",stdout);
    cin>>n>>m;
    cin>>xs>>ys;
    cin>>xf>>yf;
    depe();
    cout<<dp[xf][yf]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
