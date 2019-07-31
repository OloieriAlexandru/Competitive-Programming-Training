#include <bits/stdc++.h>
#define lld long long
#define mod 1000000009LL
using namespace std;
lld n, m, k, ans, gr;
lld cat, rest;
lld logExp(lld a, lld n)
{
    if (!n) return 1;
    if (n & 1) return (a * (logExp((a*a)%mod,n>>1) % mod)%mod);
    return logExp((a*a)%mod,n>>1);
}
int main()
{
    cin>>n>>m>>k;
    lld im = m;

    cat = n / k;
    rest = n % k;

    m -= rest; // la astea pot sa raspund sigur, fara nici o problema

    if (1LL * (k-1) * cat >= m)
    {
        cout<<im<<'\n';
        return 0;
    }

    // trebuie sa dublez de cateva ori

    lld pluss = (m - (1LL * (k-1) * cat)%mod)%mod;
    // atatea dublez
    lld add = (m - (1LL * pluss * k)%mod)%mod;
    if (add < 0) add = mod + add;

    lld pw = (logExp(2,pluss + 1) - 2) % mod;
    if (pw < 0) pw = mod + pw;

    ans = (add + (((1LL * k)%mod) * pw)%mod + rest)%mod;
    cout<<ans<<'\n';
    return 0;
}
