#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
long long a[nmax], n, k, poz, ans;
bool ok(long long m)
{
    // vad daca pot sa fac mediana m
    if (a[poz] >= m) return true;
    long long need = 0;
    for (int i=poz;i<=n;++i)
    {
        if (a[i] >= m) break;
        need += (m-a[i]);
    }
    return need <= k;
}
int main()
{
    cin>>n>>k;
    poz = n / 2 + 1;
    for (int i=1; i<=n; ++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long st = 0, dr = a[n] + k;
    while (st <= dr)
    {
        long long m = 1LL * (st + dr) / 2;
        if (ok(m))
        {
            ans = max(ans, m);
            st = m + 1;
        }
        else dr = m-1;
    }
    cout<<ans<<'\n';
    return 0;
}
