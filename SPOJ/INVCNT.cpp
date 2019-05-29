#include <stdio.h>
#define LMAX 200005
#define NMAX 10000005
#define lld long long
#define MAX(a,b) a>b?a:b
using namespace std;
int a[LMAX];
int AIB[NMAX];
int n;
int maxim;
int cnt(int x)
{
    int r = 0;
    for (;x;x-=(x&(-x)))
    {
        r+=AIB[x];
    }
    return r;
}
void update(int x)
{
    for (;x<=maxim;x+=(x&(-x)))
        ++AIB[x];
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int q=1;q<=t;++q)
    {
        scanf("%d",&n);
        maxim = -1;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            maxim = MAX(maxim, a[i]);
        }
        lld ans=0;
        for (int i=n;i>=1;--i)
        {
            ans += cnt(a[i]-1);
            update(a[i]);
        }
        for (int i=1;i<=n;++i)
            a[i] =0;
        for (int i=1;i<=maxim;++i)
            AIB[i]=0;
        printf("%lld\n", ans);
    }
    return 0;
}
