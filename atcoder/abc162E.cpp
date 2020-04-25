#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax 100005
#define lld long long
#define mod 1000000007LL
using namespace std;

lld a[nmax];

lld expLog(lld a, lld n){
    if (!n){
        return 1LL;
    }
    if (n & 1){
        return (a * expLog((a*a)%mod, n>>1))%mod;
    }
    return expLog((a*a)%mod, n>>1);
}

int main()
{
    int n, k;
    cin>>n>>k;
    lld ans = 0;
    for (int i=k;i>=1;--i){
        a[i] = expLog(k/i,n);
        lld sub = 0;
        for (int j=i+i;j<=k;j+=i){
            sub = (sub + a[j]) % mod;
        }
        a[i] -= sub;
        a[i] %= mod;
        if (a[i] < mod){
            a[i] = a[i] + mod;
        }
        ans = (ans + 1LL * i * a[i]) % mod;
    }
    cout<<ans<<'\n';
    return 0;
}
