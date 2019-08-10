#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, a[nmax], p[nmax], ln[nmax], ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i], p[a[i]] = i;
    ln[1] = 1;
    for (int i=2; i<=n; ++i)
        if (p[i-1] < p[i])
            ln[i] = ln[i-1] + 1;
        else
            ln[i] = 1;
    for (int i=1; i<=n; ++i)
        ans = max(ans, ln[i]);
    cout<<n-ans<<'\n';
    return 0;
}
