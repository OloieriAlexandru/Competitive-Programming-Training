#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int t, n, k, minn, maxx, x;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>x;
        minn = maxx = x;
        for (int i=2;i<=n;++i)
        {
            cin>>x;
            minn = min(minn, x);
            maxx = max(maxx, x);
        }
        if (maxx - minn > 2 * k)
            cout<<"-1\n";
        else
            cout<<minn + k<<'\n';
    }
    return 0;
}
