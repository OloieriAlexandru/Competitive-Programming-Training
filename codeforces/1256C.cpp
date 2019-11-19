#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, m, d, a[nmax], ans[nmax], poz;
bool ok;
int main()
{
    cin>>n>>m>>d;
    int sum = 0;
    for (int i=1; i<=m; ++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    if ((m+1)*(d-1)+sum >=n)
    {
        ok = true;
        int len = (n-sum)/(m+1);
        int cnt = (n-sum)%(m+1);
        for (int i=1; i<=m; ++i)
        {
            for (int j=0; j<len+(i<=cnt); ++j)
            {
                ans[++poz] = 0;
            }
            for (int j=0; j<a[i]; ++j)
            {
                ans[++poz] = i;
            }
        }
        while (poz+1<=n)
        {
            ans[++poz] = 0;
        }
    }
    else
    {
        ok = false;
    }

    if (!ok)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i=1; i<=n; ++i)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
