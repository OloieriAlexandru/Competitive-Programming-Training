#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, ans;
int t;
lld pw[65], sub[65];
int main()
{
    cin>>t;
    pw[1] = 1;
    sub[1] = 1;
    for (int i=2; i<=62; ++i)
        pw[i] = pw[i-1]*2,
        sub[i] = sub[i-1] + pw[i];
    while(t--)
    {
        cin>>n;
        ans = n * (n+1) / 2;
        for (int i=62; i>=1; --i)
            if (n >= pw[i])
            {
                ans -= sub[i];
                ans -= sub[i];
                break;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
