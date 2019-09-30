#include <bits/stdc++.h>
using namespace std;
int n, x, y, g;
int main()
{
    cin>>n>>x;
    for (int i=1;i<=n;++i)
    {
        cin>>y;
        g = __gcd(g, y);
    }
    if (x % g == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
