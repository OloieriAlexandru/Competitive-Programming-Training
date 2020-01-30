#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
#define mod 1000000007
using namespace std;
int n, k, a[nmax];
lld ans = 0;
lld sum[nmax], fact[nmax];
namespace oMath
{
#define lld long long
    void extendedGcd(lld &x, lld &y, lld a, lld b)
    {
        if (!b)
            x = 1, y = 0;
        else
        {
            extendedGcd(x, y, b, a%b);
            lld aux = x;
            x = y;
            y = aux - y*(a/b);
        }
    }

    lld modularInverse(lld a, lld n)
    {
        lld x, y;
        extendedGcd(x, y, a, n);
        if (x < 0) x = n + x;
        return x;
    }
}
lld comb(lld n, lld k){
    lld inm1 = oMath::modularInverse(fact[k], mod);
    lld inm2 = oMath::modularInverse(fact[n-k],mod);
    lld ans = fact[n] * inm1;
    ans %= mod;
    ans *= inm2;
    ans %= mod;
    if (ans < 0){
        ans = mod + ans;
    }
    return ans;
}

int main()
{
    cin>>n>>k;
    fact[0] = 1;
    for (int i=1;i<=n;++i){
        fact[i] = (fact[i-1]*i)%mod;
    }
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    lld ans = 0;
    for (int i=1;i<=n;++i){
        if (i >= k){
            lld add = (comb(i-1, k-1)*a[i])%mod;
            ans += add;
            ans %= mod;
            if (ans < 0){
                ans = mod + ans;
            }
        }
        if (i <= n-k+1){
            lld sub = (comb(n-i,k-1)*a[i])%mod;
            ans -= sub;
            ans %= mod;
            if (ans < 0){
                ans = mod + ans;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
