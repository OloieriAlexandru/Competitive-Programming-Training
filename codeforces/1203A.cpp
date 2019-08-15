#include <bits/stdc++.h>
#define nmax 205
using namespace std;
int a[nmax*4];
int main()
{
    int t, n, poz;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=n+1; i<=n+n; ++i)
        {
            cin>>a[i];
            if (a[i] == 1) poz = i;
        }
        for (int i=1; i<=n; ++i)
            a[i] = a[i+n];
        for (int i=2*n+1; i<=3*n; ++i)
            a[i] = a[i-n];
        bool ok1 = true;
        for (int i=poz+1; i<=poz+n-1 && ok1; ++i)
            if (a[i] - a[i-1] != 1)
                ok1 = false;
        if (ok1)
        {
            cout<<"YES\n";
            continue;
        }
        ok1 = true;
        for (int i=poz-1; i>=poz-n+1 && ok1; --i)
            if (a[i] - a[i+1] != 1)
                ok1 = false;
        if (ok1)
        {
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}
