#include <bits/stdc++.h>
#define ld long double
#define lld long long
using namespace std;

ld logExp(ld act, lld n)
{
    if (n == 0) return 1.0;
    if (n & 1) return act * (logExp(act * act, n >> 1));
    return logExp(act * act, n >> 1);
}

int main()
{
    int n;
    lld t;
    cin>>n>>t;
    ld ans = 1.000000011;
    ans = logExp(ans, t) * n;
    cout<<setprecision(20)<<fixed<<ans<<'\n';
    return 0;
}
