#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, k, ans, a, b, add, nw;
int main()
{
    cin>>n>>k>>a>>b;
    if (k == 1)
    {
        cout<<(n-1) * a<<'\n';
        return 0;
    }
    while (n > 1)
    {
        if (n < k)
        {
            ans += (n-1) * a;
            n = 1;
            continue;
        }
        if (n % k == 0)
        {
            nw = n / k;
            add = (n - nw) * a;
            add = min(add, b);
            ans += add;
            n = nw;
        }
        else
        {
            add = n % k;
            n -= add;
            ans += add * a;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
