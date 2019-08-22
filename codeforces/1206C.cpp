#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, ans[nmax], nn;
int main()
{
    cin>>n;
    if (!(n%2))cout<<"NO\n";
    else
    {
        nn = 2 * n;
        for (int i=1; i<=n; ++i)
            if (!(i%2)) ans[i] = 2*i-1, ans[i+n]=2*i;
            else ans[i] = 2*i, ans[i+n]=2*i-1;
        cout<<"YES\n";
        for (int i=1; i<=nn; ++i)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
