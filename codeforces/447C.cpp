#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int l[nmax], r[nmax], a[nmax], n, ans, add;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    if (n == 1) ans = 1;
    for (int i=1; i<=n; ++i)
    {
        add = 1;
        l[i] = add;
        ans = max(ans, add+1);
        while (i < n && a[i] < a[i+1])
        {
            ++add;
            l[i+1] = add;
            ans = max(ans, add + 1);
            ++i;
        }
    }
    for (int i=n; i>=1; --i)
    {
        add = 1;
        r[i] = add;
        ans = max(ans, add+1);
        while (i > 1 && a[i] > a[i-1])
        {
            ++add;
            r[i-1] = add;
            ans = max(ans, add + 1);
            --i;
        }
    }
    for (int i=1; i<=n; ++i)
    {
        if (a[i+1] - a[i-1] > 1)
            ans = max(r[i+1] + l[i-1] + 1, ans);
    }
    ans = min(ans, n);
    printf("%d\n", ans);
    return 0;
}
