#include <bits/stdc++.h>
#define nmax 20005
#define mod 1000000000
#define lld long long
using namespace std;
int n, k, dej, ans;
int aib[11][nmax], a[nmax];
void update(int k, int poz, int add)
{
    for (int i=poz;i<=n;i+=(i&(-i)))
        aib[k][i] = (aib[k][i] + add) % mod;
}
int query(int k, int poz)
{
    int ans = 0;
    for (int i=poz;i>=1;i-=(i&(-i)))
        ans = (ans + aib[k][i] ) % mod;
    return ans;
}
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<k;++j)
        {
            dej = query(j, n) - query(j, a[i]);
            if (dej < 0) dej = mod + dej;
            update(j+1, a[i], dej);
        }
        update(1, a[i], 1);
    }
    ans = query(k, n);
    if (ans < 0) ans = mod + ans;
    cout<<ans<<'\n';
    return 0;
}