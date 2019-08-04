#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int a[nmax], mod[nmax], n, t, act[nmax], maxx[nmax];
int x, y, m;
int lstmod, lsti, maxmod;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        cin>>a[i];
    scanf("%d",&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d",&t);
        if (t == 1)
        {
            scanf("%d %d",&x,&y);
            mod[x] = i;
            a[x] = y;
        }
        else
        {
            scanf("%d",&x);
            if (x > maxmod)
                maxmod = x;
            act[i] = x;
        }
    }
    for (int i=m;i>=1;--i)
        maxx[i] = max(maxx[i+1], act[i]);
    for (int i=1;i<=n;++i)
    {
        if (!mod[i])
            printf("%d ", max(maxmod, a[i]));
        else
        {
            printf("%d ", max(maxx[mod[i]+1], a[i]));
        }
    }
    printf("\n");
    return 0;
}
