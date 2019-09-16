#include <bits/stdc++.h>
#define nmax 25005
using namespace std;
int fv[nmax], n, x, ans[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        ++fv[x];
    }
    for (int i=nmax-2;i>=1;--i)
        fv[i] += fv[i+1];
    for (int i=1;i<nmax;++i)
        if (!fv[i]) break;
        else ++ans[fv[i]];
    for (int i=nmax-2;i>=1;--i)
        ans[i] += ans[i+1];
    for (int i=1;i<nmax;++i)
        if (!ans[i]) break;
        else printf("%d\n", ans[i]);
    return 0;
}
