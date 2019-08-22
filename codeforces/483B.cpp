#include <bits/stdc++.h>
#define lld long long
#define inf 1000000000000LL
using namespace std;
lld cnt1, cnt2, x, y;
bool ok(lld m)
{
    lld divs1 = m / x;
    lld divs2 = m / y;
    lld divsb = m / (x * y);
    divs1 -= divsb;
    divs2 -= divsb;
    lld rm1 = max(0LL, cnt1 - divs2);
    lld rm2 = max(0LL, cnt2 - divs1);
    return (m-(divs1+divs2+divsb))>=(rm1+rm2);
}
int main()
{
    cin>>cnt1>>cnt2>>x>>y;
    lld st = 0, dr = inf, m, ans = 0;
    while (st <= dr)
    {
        m = (st + dr) / 2;
        if (ok(m))
        {
            ans = m;
            dr = m-1;
        } else st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
