#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, mm, a[nmax], ans;
bool ok(int m)
{
    int votes = 0, used = 0;
    for (int i=1; i<=n; ++i)
    {
        if (votes >= a[i])
            ++votes;
        else
        if (used < m)
            ++used, ++votes;
    }
    return votes >= mm;
}
int main()
{
    scanf("%d %d",&n,&mm);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    int st = 0, dr = n;
    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (ok(m))
            ans = m, dr = m - 1;
        else st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
