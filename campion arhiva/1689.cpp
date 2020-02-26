#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
#define inf 999999999999999LL
using namespace std;
int n, a[nmax], k;
lld s[nmax], smax[nmax], dmax[nmax];
int main()
{
    freopen("castig.in","r",stdin);
    freopen("castig.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=k;++i){
        s[1] += a[i];
    }
    smax[1] = s[1];
    for (int i=k+1;i<=n;++i){
        s[i-k+1] = s[i-k] - a[i-k] + a[i];
        smax[i-k+1] = max(smax[i-k], s[i-k+1]);
    }
    dmax[n-k+1] = s[n-k+1];
    for (int i=n-k;i>=1;--i){
        dmax[i] = max(dmax[i+1], s[i]);
    }
    lld ans = dmax[k+1];
    for (int i=2;i<=k;++i){
        ans=min(ans,dmax[i+k]);
    }
    for (int i=k+1;i<=n-k+1;++i){
        ans = min(ans, max(smax[i-k],dmax[i+k]));
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
