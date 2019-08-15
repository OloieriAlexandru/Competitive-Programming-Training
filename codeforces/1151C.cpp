#include <bits/stdc++.h>
#define lld long long
#define mod 1000000007
using namespace std;
lld l, r;
lld add(lld a, lld b)
{
    a %= mod;
    b %= mod;
    a = a + b - 1;
    a %= mod;
    b %= mod;
    a *= b;
    a %= mod;
    return a;
}
lld sum(lld x)
{
    lld ret = 0;
    lld cx = x, p2 = 1, vi = 1, vp = 2;
    bool odd = true;
    while (cx)
    {
        lld sc = min(cx, p2);
        if (odd)
        {
            ret = (ret + add(vi, sc)) % mod;
            vi += (p2 * 2);
        }
        else
        {
            ret = (ret + add(vp, sc)) % mod;
            vp += (p2 * 2);
        }
        odd = !odd;
        cx -= sc;
        p2 *= 2;
    }
    return ret;
}
int main()
{
    cin>>l>>r;
    lld ans = sum(r) - sum(l-1);
    if (ans < 0) ans = mod + ans;
    cout<<ans<<'\n';
    return 0;
}
