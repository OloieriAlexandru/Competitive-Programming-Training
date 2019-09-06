#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, a[nmax], dif[nmax], act, ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
        dif[i] = a[i-1] - a[i];
    for (int i=1; i<=n; ++i)
    {
        act += dif[i];
        if (act < 0)
            ans += -act, act = 0;
    }
    cout<<ans<<'\n';
    return 0;
}
