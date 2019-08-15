#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
typedef long long ll;
int n;
ll x, g;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        if (i == 1) g = x;
        else g = __gcd(g, x);
    }
    if (g == 1)
        cout<<"1\n";
    else
    {
        ll af = 2;
        for (ll i=2;i*i<=g;++i)
            if (g % i == 0)
            {
                if (i * i == g) ++af;
                else af += 2;
            }
        cout<<af<<'\n';
    }
    return 0;
}
