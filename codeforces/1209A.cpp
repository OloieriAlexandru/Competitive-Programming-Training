#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, ans, a[nmax], uz[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        if (uz[i]) continue;
        ++ans;
        uz[i] = true;
        for (int j=i+1;j<=n;++j)
            if (a[j] % a[i] == 0)
                uz[j] = true;
    }
    cout<<ans<<'\n';
    return 0;
}
