#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, k, ans = 0, z = 1, rm, tot;
int main()
{
    cin>>n>>k;
    tot = 1;
    while (1)
    {
        if (tot >= n)
        {
            cout<<ans<<'\n';
            return 0;
        }
        if (z >= k)
        {
            break;
        }
        ++ans;
        tot += min(k,z);
        z *= 2;
    }
    rm = n - tot;
    if (rm)
        ans += rm / k + (rm % k ? 1 : 0);
    cout<<ans<<'\n';
    return 0;
}
