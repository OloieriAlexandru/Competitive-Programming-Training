#include <bits/stdc++.h>
#define nmax 1005
#define pb push_back
using namespace std;
int g, dp[nmax], a[nmax], n;
int sol[nmax], ans, ln, sum, act;
bool ok;
void gen(int k)
{
    if (ok) return;
    if (sum > ans) return;
    if (sum == ans)
    {
        ln = k-1;
        ok = true;
        return;
    }
    for (int i=sol[k-1]+1;i<=n;++i)
    {
        sum += a[i];
        sol[k] = i;
        gen(k+1);
        if (ok)
            return;
        sum -= a[i];
    }
}
int main()
{
    while(true)
    {
        scanf("%d",&g);
        if (!g) break;
        scanf("%d",&n);
        for (int i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        for (int i=1; i<=n; ++i)
        {
            for (int j=g; j>0; --j)
            {
                if (j - a[i] <= 0) break;
                if (!dp[j-a[i]]) continue;
                dp[j] = dp[j-a[i]] + 1;
            }
            dp[a[i]] = 1;
        }
        act = g;
        while (act >= 1)
        {
            if (dp[act]) break;
            --act;
        }
        ans = act;
        ok = 0;
        for (int i=1;i<=n;++i)
        {
            sol[1] = i;
            sum = a[i];
            gen(2);
            if (ok) break;
        }
        for (int i=1;i<=ln;++i)
            printf("%d ", a[sol[i]]);
        printf("%d\n", ans);
        for (int i=1;i<=g;++i)
            dp[i] = 0;
    }
    return 0;
}
