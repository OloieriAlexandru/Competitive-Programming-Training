#include <bits/stdc++.h>
using namespace std;

int main()
{
    double ans;
    int n, x;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        ans += x;
    }
    ans /= n;
    cout<< setprecision(8)<< fixed<<ans<<'\n';
    return 0;
}
