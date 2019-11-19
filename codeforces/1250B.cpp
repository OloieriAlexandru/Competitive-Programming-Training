#include <bits/stdc++.h>
#define nmax 8888
#define lld long long
#define inf 999999999999999LL
using namespace std;
int cnt[nmax], n, k, x;
lld ans = inf;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++cnt[x];
    }
    sort(cnt+1,cnt+k+1);
    for (int i=0;i<=k;i+=2){
        lld act = -1;
        int mul = i / 2;
        for (int j=1;j<=i;++j){
            act=max(act, 1LL*cnt[j]+cnt[i-j+1]);
        }
        for (int j=i+1;j<=k;++j){
            act=max(act, 1LL*cnt[j]);
            ++mul;
        }
        ans = min(ans, act*mul);
    }
    cout<<ans<<'\n';
    return 0;
}
