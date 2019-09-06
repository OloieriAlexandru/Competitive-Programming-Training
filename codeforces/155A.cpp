#include <bits/stdc++.h>
#define nmax 1000
using namespace std;
int main()
{
    int n, a[nmax], ans = 0;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int minn = a[1], maxx = a[1];
    for (int i=1;i<=n;++i)
    {
        if (a[i] > maxx) ++ans, maxx = a[i];
        if (a[i] < minn) ++ans, minn = a[i];
    }
    cout<<ans<<'\n';
    return 0;
}
