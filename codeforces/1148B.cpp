#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, m, ta, tb, k, ans = 0;
int a[nmax], b[nmax];
int main()
{
    scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;++i)
        scanf("%d",&b[i]);
    if (k >= n || k>=m) {
        printf("-1\n");
        return 0;
    }
    int st = 1;
    for (int i=0;i<=k;++i)
    {
        while (st <= m && b[st] < (a[i+1] + ta)) ++st;
        if (st == m+1 || st + (k-i) > m){
            printf("-1\n");
            return 0;
        }
        ans = max(ans, b[st + (k-i)] + tb);
    }
    cout<<ans<<'\n';
    return 0;
}
