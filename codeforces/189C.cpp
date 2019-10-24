#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int a[nmax], b[nmax], p[nmax];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
    {
        cin>>b[i];
        p[b[i]] = i;
    }
    for (int i=1; i<=n; ++i)
        a[i] = p[a[i]];
    int ans = 2;
    while (ans <= n)
    {
        if (a[ans-1] > a[ans]) break;
        ++ans;
    }
    cout<<n-(ans-1)<<'\n';
    return 0;
}
