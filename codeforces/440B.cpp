#include <bits/stdc++.h>
#define nmax 50005
#define lld long long
using namespace std;
int n, a[nmax], nxt[nmax], lst, k, curr, need, rm;
lld sum, ans;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    k = sum / n;
    for (int i=1; i<=n; ++i)
        if (a[i] > k)
            nxt[lst] = i, lst = i;
    curr = 0;
    for (int i=1; i<=n; ++i)
    {
        if (a[i] < k)
        {
            need = k - a[i];
            while (need)
            {
                if (a[curr] <= k)
                    curr = nxt[curr];
                rm = a[curr] - k;
                if (rm > need)
                {
                    ans += 1LL * need * abs(i-curr);
                    a[curr] -= need;
                    break;
                }
                else
                {
                    ans += 1LL * rm * abs(i-curr);
                    a[curr] = k;
                    need -= rm;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
