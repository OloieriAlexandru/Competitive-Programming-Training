#include <bits/stdc++.h>
#define nmax 1000
using namespace std;
int n, m, a[nmax], b[nmax];
bool ex[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        ex[a[i]] = true;
    }
    cin>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>b[i];
        ex[b[i]] = true;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    {
        if (!ex[a[i]+b[j]])
        {
            cout<<a[i]<<' '<<b[j]<<'\n';
            return 0;
        }
    }
    return 0;
}
