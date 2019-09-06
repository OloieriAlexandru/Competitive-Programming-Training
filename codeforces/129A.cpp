#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, a[nmax], s, ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s += a[i];
    }
    for (int i=1;i<=n;++i)
    {
        if ((s - a[i])%2 == 0)++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
