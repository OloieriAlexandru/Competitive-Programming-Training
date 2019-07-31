#include <bits/stdc++.h>
#define nmax 105
using namespace std;

int main()
{
    int n, ans = 0, a[nmax];
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    ans += a[1] + a[n];
    for (int i=2;i<=n;++i)
        ans += max(a[i], a[i-1]);
    cout<<ans<<'\n';
    return 0;
}
