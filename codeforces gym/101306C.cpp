#include <bits/stdc++.h>
#define nmax 25
using namespace std;
int n, x, y, mars[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y;
        ++mars[x];
        --mars[y];
    }
    int act = 0;
    for (int i=0;i<=24;++i)
    {
        act += mars[i];
        mars[i] = act;
    }
    int ans = 0;
    for (int i=0;i<=24;++i)
        ans = max(ans, mars[i]);
    cout<<ans<<'\n';
    return 0;
}
