#include <bits/stdc++.h>
#define lld long long
using namespace std;
int n, x, minuss, z;
lld ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (!x){++ans; ++z;continue;}
        if (x < 0) x = -x, ++minuss;
        ans += (x-1);
    }
    if (minuss%2 && !z)ans+=2;
    cout<<ans<<'\n';
    return 0;
}
