#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 205
#define inf 99
using namespace std;
int n, m, a[nmax][nmax], ans;
int minnn, cr, dp[10005];
vector<int>minn[10005];
void printt(int k){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (k >= dp[a[i][j]]) {
                printf("0 ");
            } else {
                printf("%d ", minn[a[i][j]][k]);
            }
        }
        printf("\n");
    }
}
int main()
{
    freopen("operatii2.in","r",stdin);
    freopen("operatii2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=10000;++i){
        minnn = inf;
        for (int j=1;i-j*j>=0;++j){
            if (minnn > dp[i-j*j] + 1){
                minnn = dp[i-j*j] + 1;
                cr = j;
            }
        }
        dp[i] = dp[i-cr*cr] + 1;
        minn[i] = minn[i-cr*cr];
        minn[i].push_back(cr);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (dp[a[i][j]] > ans){
                ans = dp[a[i][j]];
            }
        }
    }
    printf("%d\n",ans);
    for (int i=0;i<ans;++i){
        printt(i);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
