#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int n, q, sum[nmax], l, r, ans;
lld x;
int minOp(lld x)
{
    int ret = 0;
    while (x > 1)
    {
        if (x % 2)
            ++ret, --x;
        x/=2, ++ret;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for (int i=1;i<=n;++i)
        {
            scanf("%lld",&x);
            sum[i] = sum[i-1];
            sum[i] += minOp(x);
        }
        for (int i=1;i<=q;++i)
        {
            scanf("%d %d",&l,&r);
            ans = sum[r] - sum[l-1];
            printf("%d\n", ans);
        }
    }
    return 0;
}
