#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
#define mod 1000000007
using namespace std;
int n;
lld x, sum, a[nmax];
map<lld,int>mp;
lld pw(lld mul, lld cnt){
    if (!cnt) return 1;
    if ((cnt & 1) == 0) return pw((mul*mul)%mod,cnt>>1);
    return (mul*pw((mul*mul)%mod,cnt>>1))%mod;
}
int main()
{
    scanf("%d %lld",&n,&x);
    for (int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    for (int i=1;i<=n;++i){
        ++mp[sum-a[i]];
    }
    lld up;
    while (1){
        lld act = (*mp.begin()).first;
        int fv = (*mp.begin()).second;
        mp.erase(act);
        if (fv % x){
            up = act;
            if (up > sum) up = sum;
            break;
        }
        mp[act+1] += fv/x;
    }
    printf("%lld\n", pw(x, up));
    return 0;
}
