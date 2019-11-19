#include <bits/stdc++.h>
#define nmax 100005
#define mod 1000000007LL
#define lld long long
using namespace std;
int n,a[nmax],jump[nmax],j[nmax];
lld mars[nmax], ans1, ans2, dp[nmax], val;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        scanf("%d",&a[i]);
        ans1+=a[i];
    }
    for (int i=1;i<n;++i){
        scanf("%d",&j[i]);
    }
    for (int i=n;i>=1;--i){
        if (a[i]){
            jump[i]=0;
            continue;
        }
        jump[i]=jump[i+1]+1;
    }
    dp[1]=1;
    for (int i=1;i<=n;++i){
        val=(val+mars[i])%mod;
        dp[i]=(dp[i]+val)%mod;
        if (dp[i]<0){
            dp[i]=mod+dp[i];
        }
        if (i==n){
            break;
        }
        int lst;
        if (!jump[i+1]){
            lst=i+1;
        } else {
            lst=min(n,i+min(j[i],jump[i+1]+1));
        }
        if (lst < i+1){
            lst = i+1;
        }
        mars[i+1]+=dp[i];
        mars[i+1]%=mod;
        mars[lst+1]-=dp[i];
        mars[lst+1]%=mod;
        if (mars[lst+1]<0){
            mars[lst+1]=mod+mars[lst+1];
        }
    }
    ans2=dp[n];
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
