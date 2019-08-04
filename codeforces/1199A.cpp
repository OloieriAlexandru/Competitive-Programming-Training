#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a[nmax];
int main()
{
    int n, x, y;
    cin>>n>>x>>y;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        int st = max(1,i-x);
        int dr = min(n,i+y);
        bool ok = true;
        for (int j=st;j<=dr;++j)
        {
            if (j == i) continue;
            if (a[i] >= a[j]) ok = false;
        }
        if (ok)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    return 0;
}
