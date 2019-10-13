#include <bits/stdc++.h>
#define nmax 10005
using namespace std;
int n, fv[nmax], ans, maxx, x;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxx = 0, ans = 0;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            ++fv[x];
            maxx = max(maxx, x);
        }
        for (int i=1;i<=maxx;++i)
            ans = max(ans, fv[i] + fv[i-1]);
        cout<<ans<<'\n';
        for (int i=1;i<=maxx;++i)
            fv[i] = 0;
    }
    return 0;
}
