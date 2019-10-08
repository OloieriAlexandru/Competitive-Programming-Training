#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int a[nmax], t, n, sum,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum = 0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        d = sum / n;
        if (sum%n == 0)
            cout<<d<<'\n';
        else
            cout<<d+1<<'\n';
    }
    return 0;
}
