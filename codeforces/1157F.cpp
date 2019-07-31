#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, a[nmax], fv[nmax], maxx;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        ++fv[a[i]];
        maxx = max(maxx, a[i]);
    }
    int ans = -1;
    int lft, rgh;
    for(int i=1; i<=maxx; ++i)
    {
        if (!fv[i]) continue;
        int curr = fv[i];
        int l = i, j, r;
        for (j=i+1; fv[j]>=2; ++j)
            curr += fv[j];
        if (fv[j])
            r = j, ++curr;
        else
            r = j-1;
        if (curr >= ans)
        {
            ans = curr;
            lft = l, rgh = r;
        }
        i = j-1;
    }
    printf("%d\n", ans);
    for (int i=0; i<fv[lft]; ++i)
        printf("%d ", lft);
    for (int i=lft+1; i<rgh; ++i)
        for (int j=0; j<fv[i]-1; ++j)
            printf("%d ", i);
    if (lft < rgh)
    {
        for (int i=0; i<fv[rgh]; ++i)
            printf("%d ", rgh);
        for (int i=rgh-1; i>lft; --i)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
