#include <bits/stdc++.h>
#define nmax 1000010
#define lld long long
using namespace std;
int n;
unsigned int sum[nmax], a[nmax], v[3], minn[nmax];
int main()
{
    scanf("%u",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%u %u %u",&v[0],&v[1],&v[2]);
        sort(v,v+3);
        a[i] = v[0] + v[1] + 2;
        sum[i] = v[0] + v[1] + v[2];
        minn[i] = a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        int st = 1, dr = n, index;
        while (st <= dr)
        {
            int m = (st + dr) / 2;
            if (a[m] <= sum[i])
            {
                index = m;
                st = m + 1;
            }
            else dr = m - 1;
        }
        if (dr == 0) printf("0 ");
        else
        {
            if (minn[i] <= sum[i]) --index;
            printf("%d ", index);
        }
    }
    return 0;
}
