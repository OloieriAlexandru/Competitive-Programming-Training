#include <bits/stdc++.h>
#define lld long long
using namespace std;
int cnt[1025], n, mask, actMask;
bool ex[10];
lld x, ans;
int main()
{
    for (int i=0;i<10;++i)
        mask ^= (1<<i);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        while (x)
            ex[x%10] = true, x/=10;
        actMask = mask;
        for (int j=0;j<10;++j)
            if (!ex[j])
                actMask ^= (1<<j);
        for (int j=1;j<(1<<10);++j)
            if (j & actMask)
                ans += cnt[j];
        memset(ex,0,sizeof(ex));
        ++cnt[actMask];
    }
    printf("%lld\n",ans);
    return 0;
}