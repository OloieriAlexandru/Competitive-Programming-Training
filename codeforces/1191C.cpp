#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
using namespace std;
ll n, k, ans, del, start, dell;
int m;
ll a[nmax];
int main()
{
    scanf("%lld %d %lld",&n,&m,&k);
    for (int i=1;i<=m;++i)
        scanf("%lld",&a[i]);
    for (int i=1;i<=m;++i)
    {
        start = ((a[i]-del) - ((a[i] - del) % k ? ((a[i]-del)%k) : k));
        dell = del;
        while (start <= (a[i]-dell) && (a[i]-dell) <= start + k)
            ++i, ++del;
        --i, ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
