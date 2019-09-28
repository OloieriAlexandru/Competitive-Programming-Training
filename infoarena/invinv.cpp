#include <bits/stdc++.h>
#define nmax 600005
#define lld long long
using namespace std;
int n;
lld k;
int ans[nmax];
int main()
{
    freopen("invinv.in","r",stdin);
    freopen("invinv.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld",&n,&k);
        int dr = n;
        int st = 1;
        for (int i=1;i<=n;++i)
        {
            if (n-i <= k)
            {
                k-=(n-i);
                ans[i] = dr;
                --dr;
            }
            else
            {
                ans[i] = st;
                ++st;
            }
        }
        for (int i=1;i<=n;++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
