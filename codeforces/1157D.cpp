#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int minn, n, k, ans[nmax];
int main()
{
    scanf("%d %d",&n,&k);
    if ((1LL * k * (k+1)) / 2 > n)
    {
        printf("NO\n");
        return 0;
    }
    minn = (1LL * k * (k+1)) / 2;
    for (int i=1;i<=k;++i)
        ans[i] = (n - minn) / k;
    for (int i=k,j=1;j<=(n-minn)%k;++j,--i)
        ++ans[i];
    for (int i=1;i<=k;++i)
        ans[i] += i;
    if (n - minn != k-1 || k == 1)
    {
        printf("YES\n");
        for (int i=1;i<=k;++i)
            printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    if (k == 2 || k == 3)
    {
        printf("NO\n");
        return 0;
    }
    --ans[2];
    ++ans[k];
    printf("YES\n");
    for (int i=1;i<=k;++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
