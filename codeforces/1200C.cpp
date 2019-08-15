#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, m, s1, s2, e1, e2, g;
int t;
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
    cin>>n>>m>>t;
    g = gcd(n, m);
    while (t--)
    {
        cin>>s1>>s2>>e1>>e2;
        --s2, --e2;
        if (s1 == 1) s2 /= (n / g);
        else s2 /= (m / g);
        if (e1 == 1) e2 /= (n / g);
        else e2 /= (m / g);
        if (s2 == e2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
