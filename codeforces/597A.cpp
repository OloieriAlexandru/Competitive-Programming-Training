#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll k, a, b;
int main()
{
    cin>>k>>a>>b;
    ll r = abs(a % k);
    a += (r == 0 ? 0 : (a < 0 ? r : k - r));
    r = abs(b%k);
    b -= (r == 0? 0 : (b < 0 ? k-r : r));
    ll ans;
    if (a <= b)
        ans = (b - a) / k + 1;
    else ans = 0;
    cout<<ans<<'\n';
    return 0;
}
