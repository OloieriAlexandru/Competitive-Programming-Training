#include <bits/stdc++.h>
using namespace std;
int t;
long long st, dr;
long long p2[66];
long long ans(long long l, long long r)
{
    if (l == r) return l;
    for (int i=62; i>=0; --i)
    {
        if (p2[i] <= r)
        {
            if (p2[i] <= l)
                return ans(l-p2[i],r-p2[i]) + p2[i];
            if (p2[i+1]-1<=r) return p2[i+1]-1;
            return p2[i]-1;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&t);
    p2[0] = 1;
    for (int i=1; i<63; ++i)
        p2[i] = p2[i-1] * 2;
    while(t--)
    {
        scanf("%lld %lld",&st,&dr);
        printf("%lld\n", ans(st,dr));
    }
    return 0;
}
