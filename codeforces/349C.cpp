#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int n, a[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    lld sum = 0;
    for (int i=1;i<=n;++i)
        sum += a[i];
    lld ans = sum / (n-1);
    if (sum % (n-1))++ans;
    ans = max(ans, (lld)a[n]);
    cout<<ans<<'\n';
    return 0;
}
