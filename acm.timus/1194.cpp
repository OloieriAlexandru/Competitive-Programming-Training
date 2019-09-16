#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, nr, sz, g;
    long long ans = 0;
    cin>>n>>k;
    while(cin>>g)
    {
        cin>>g;
        int s = 0;
        for (int i=1;i<=g;++i)
        {
            cin>>nr>>sz;
            ans += 1LL * sz * s;
            s += sz;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
