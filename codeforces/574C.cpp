#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, x, a[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        while (x > 1 && x % 2 == 0) x /= 2;
        while (x > 1 && x % 3 == 0) x /= 3;
        a[i] = x;
    }
    bool ok = true;
    for (int i=2; i<=n && ok; ++i)
        if (a[i]!=a[i-1])
            ok = false;
    if (ok)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
