#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, ans = 0;
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            if (x) ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
