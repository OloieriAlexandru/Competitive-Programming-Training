#include <bits/stdc++.h>
#define mod 998244353LL
#define nmax 200005
#define lld long long
using namespace std;
int n, x;
vector<long long>ea;
int b[nmax];
lld ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        ea.push_back(1LL * x * i * (n-i+1));
    }
    for (int i=1; i<=n; ++i)
        cin>>b[i];
    sort(ea.begin(), ea.end());
    sort(b+1,b+n+1,[](int a, int b)
    {
        return a > b;
    });
    for (int i=0; i<ea.size(); ++i)
    {
        ans = (ans + 1LL * (ea[i] % mod) * b[i+1]) % mod;
    }
    cout<<ans<<'\n';
    return 0;
}
