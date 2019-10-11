#include <bits/stdc++.h>
#define mod 1000000007
#define nmax 2005
#define lld unsigned long long
using namespace std;
lld pascal[nmax][nmax];
int n, m, nm, k;
int main()
{
    cin>>n>>m>>k;
    nm = max(n, m);
    pascal[0][0] = 1;
    for (int i=1; i<=nm; ++i)
    {
        pascal[i][0] = 1;
        for (int j=1; j<=i; ++j)
            pascal[i][j] = ( pascal[i-1][j] + pascal[i-1][j-1] ) % mod;
    }
    lld ans = pascal[n-1][2*k] * pascal[m-1][2*k];
    ans %= mod;
    cout<<ans<<'\n';
    return 0;
}
