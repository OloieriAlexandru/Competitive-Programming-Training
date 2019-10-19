#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long
using namespace std;
lld logExp(lld a, lld n)
{
    if (!n) return 1;
    if (n & 1) return (a * (logExp((a*a)%mod, n>>1)))%mod;
    return logExp((a*a)%mod,n>>1);
}
lld n, m;
int main()
{
    cin>>n>>m;
    lld ans = logExp( logExp(2LL, m) - 1,n );
    if (ans < 0) ans = mod + ans;
    cout<<ans<<'\n';
    return 0;
}
