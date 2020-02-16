#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 100005
#define mod 666013
#define maxx 1005
#define ld long double
#define lld long long
using namespace std;
int n, nr, x, a[nmax], sum[nmax];
lld dp[nmax];
ld lg[maxx+1], bst[nmax];
int main()
{
    freopen("emax.in","r",stdin);
    freopen("emax.out","w",stdout);
    scanf("%d",&nr);
    for (int i=1;i<=nr;++i){
        scanf("%d",&x);
        x = (x < 0 ? -x : x);
        if (x){
            a[++n] = x;
        }
    }
    for (int i=1;i<=maxx;++i){
        lg[i] = log(i*1.0);
    }
    for (int i=1;i<=n;++i){
        sum[i] = sum[i-1] + a[i];
        bst[i] = -1.0;
    }
    dp[0] = 1LL;
    for (int i=1;i<=n;++i){
        for (int j=i;j>=max(1,i-10);--j){
            if ((lg[sum[i]-sum[j-1]]) + bst[j-1] > bst[i]){
                bst[i] = bst[j-1] + lg[sum[i]-sum[j-1]];
                dp[i] = (dp[j-1] * (sum[i]-sum[j-1]))%mod;
                if (dp[i]<0){
                    dp[i] = mod + dp[i];
                }
            }
        }
    }
    cout<<dp[n]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
