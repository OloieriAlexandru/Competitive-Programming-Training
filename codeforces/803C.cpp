#include <bits/stdc++.h>
#define lld unsigned long long
using namespace std;
lld ans = 0, n, k, v1, v2;
bool good(lld x)
{
    lld s = x * ((k * (k-1)) / 2);
    if (s > n) return false;
    lld rm = n-s;
    if (rm > (k-1) * x && rm % x == 0) return true;
    return false;
}
int main()
{
    cin>>n>>k;
    if (k > n)
    {
        cout<<"-1\n";
        return 0;
    }
    for (lld i = 1; i*i<=n; ++i)
    {
        if (n % i) continue;
        v1 = i;
        v2 = n / i;
        if (good(v1))
            ans = max(ans, v1);
        if (good(v2))
            ans = max(ans, v2);
    }
    if (ans != 0)
    {
        lld bg = ans;
        for (int i=1; i<k; ++i)
        {
            cout<<bg<<' ';
            bg += ans;
        }
        lld lst = n - (ans * (k*(k-1)/2));
        cout<<lst<<'\n';
    }
    else
        cout<<"-1\n";
    return 0;
}
