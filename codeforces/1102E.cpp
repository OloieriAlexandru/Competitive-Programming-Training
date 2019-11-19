#include <bits/stdc++.h>
#define mod 998244353
#define lld long long
#define nmax 200005
using namespace std;
map<int,int>lst;
int n, a[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        lst[a[i]]=i;
    }
    int ans = 1;
    int rgh = 0;
    bool ok = false;
    for (int i=1; i<=n; ++i)
    {
        rgh = max(rgh, lst[a[i]]);
        if (rgh == i)
        {
            if (ok)
            {
                ans=(2LL*ans)%mod;
            } else ok = true;
        }
    }
    printf("%d\n", ans);
    return 0;
}
