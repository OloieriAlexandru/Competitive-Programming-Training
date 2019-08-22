#include <bits/stdc++.h>
#define nmax 10005
#define lld long long
using namespace std;
int t, n, k, x, base, r;
lld ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans = 0;
        base = n / k;
        r = n % k;
        for (int i=1; i<=k; ++i)
        {
            if (i <= r)
                x = base + 1;
            else
                x = base;
            ans += x * (n-x);
        }
        cout<<ans / 2<<'\n';
    }
    return 0;
}
