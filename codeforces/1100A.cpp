#include <bits/stdc++.h>
using namespace std;
int a[105], n, k, ans, test, network;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i] == 1)++test; else ++network;
    }
    for (int i=1;i<=k;++i)
    {
        int te = 0, ne = 0;
        for (int j=i;j<=n;j+=k)
            if (a[j] == 1) ++te; else ++ne;
        ans = max(ans, abs((test-te)-(network-ne)));
    }
    cout<<ans<<'\n';
    return 0;
}
