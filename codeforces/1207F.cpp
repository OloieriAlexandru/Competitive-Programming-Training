#include <bits/stdc++.h>
#define nmax 750
#define nmax2 500005
#define lld long long
using namespace std;
const int block = nmax;
int n, t, x, y, a[nmax2];
lld ans, sum[nmax][nmax];
int main()
{
    int kt;
    scanf("%d",&kt);
    while(kt--)
    {
        scanf("%d %d %d",&t,&x,&y);
        if (t == 1)
        {
            a[x] += y;
            for (int i=1;i<nmax;++i)
                sum[i][x%i] += y;
        }
        else
        {
            if (x >= nmax)
            {
                ans = 0;
                for (int i=y;i<=500000;i+=x)
                    ans += a[i];
                printf("%lld\n", ans);
            }
            else
            {
                printf("%lld\n", sum[x][y]);
            }
        }
    }
    return 0;
}
