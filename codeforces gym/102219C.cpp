#include <bits/stdc++.h>
#define lld long long
#define inf 999999999999999999LL
using namespace std;
int tc, tc2;
lld act;
int f, t, n, s;
int main()
{
    scanf("%d",&tc);
    tc2 = 1;
    while(tc--)
    {
        lld ans = -inf;
        scanf("%d %d",&n,&s);
        for (int i=1;i<=n;++i)
        {
            scanf("%d %d",&f,&t);
            if (t <= s)
                act = f;
            else
                act = f - (t - s);
            ans = max(ans, act);
        }
        printf("Case #%d: %lld\n", tc2, ans);
        ++tc2;
    }
    return 0;
}
