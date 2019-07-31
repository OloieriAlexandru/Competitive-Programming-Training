#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld a, b, ka;
vector<lld>divs;
lld gcd(lld a, lld b)
{
    lld c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    cin>>a>>b;
    if (b < a)
        swap(a,b);
    lld x = b - a;
    lld d;
    for (d = 1;d*d<x;++d)
    {
        if (x % d) continue;
        divs.push_back(d);
        divs.push_back(x/d);
    }
    if (d * d == x)
        divs.push_back(d);
    lld ans = a * b/gcd(a,b);

    for (auto act : divs)
    {
        lld k = act - a % act;
        lld currLcm = (a + k) * (b + k) / gcd(a + k, b + k);
        if (currLcm < ans || currLcm == ans && ka < k)
            ans = currLcm, ka = k;
    }
    cout<<ka<<'\n';
    return 0;
}
