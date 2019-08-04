#include <bits/stdc++.h>
#define nmax 200005
#define lmax 2000005
using namespace std;
int n, a[nmax], p[lmax], ans, maxx, valm[lmax];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        p[a[i]]=i;
        maxx = max(maxx, a[i]);
    }
    for (int i=1; i<=2*maxx; ++i)
        if (p[i]) valm[i] = i;
        else valm[i] = valm[i-1];
    for (int i=1; i<=maxx; ++i)
    {
        if (valm[i]!=i) continue;
        for (int j=2*i-1; j<=2*maxx; j+=i)
            ans = max(ans, valm[j]%i);
    }
    cout<<ans<<'\n';
    return 0;
}
