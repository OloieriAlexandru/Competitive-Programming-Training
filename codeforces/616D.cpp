#include <bits/stdc++.h>
#define nmax 500005
using namespace std;
int n, k, a[nmax], fv[nmax * 2], act;
int l, len, lft;
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    int i;
    for (i=1; i<=n; ++i)
    {
        ++fv[a[i]];
        if (fv[a[i]] == 1)
            ++act;
        if (act > k)
        {
            len = i - 1;
            l = 1;
            break;
        }
    }
    lft = 1;
    for (; i<=n;)
    {
        while (act > k)
        {
            --fv[a[lft]];
            if (!fv[a[lft]])
                --act;
            ++lft;
        }
        if (i - lft + 1 > len)
        {
            len = i - lft + 1;
            l = lft;
        }
        ++i, ++fv[a[i]];
        if (fv[a[i]] == 1)
            ++act;
    }
    --i;
    while (act > k)
    {
        --fv[a[lft]];
        if (!fv[a[lft]])--act;
        ++lft;
    }
    if (i - lft + 1 > len)
    {
        len = i - lft + 1;
        l = lft;
    }
    cout<<l<<' '<<l+len-1<<'\n';
    return 0;
}
