#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main()
{
    cin>>n>>m;
    for (int i=0; i<=n; ++i)
    {
        if (n-i >= 0)
        {
            ans = max(ans,i+min((n-i)/2,m-2*i));
        }
    }
    cout<<ans<<'\n';
    return 0;
}
