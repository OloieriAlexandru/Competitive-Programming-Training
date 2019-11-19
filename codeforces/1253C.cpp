#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
int n, m, a[nmax];
lld ans, add[nmax];
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1; i<=n; ++i)
    {
        add[i%m]+=a[i];
        ans+=add[i%m];
        cout<<ans<<' ';
    }
    cout<<'\n';
    return 0;
}
