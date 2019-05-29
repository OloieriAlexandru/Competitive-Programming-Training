#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
int n, a[nmax], sum;
lld ans;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for (int i=n;i>=1;--i)
    {
        ans += (lld)sum*a[i];
        sum-=a[i];
        ans += (lld)sum*a[i];
    }
    cout<<ans<<'\n';
    return 0;
}