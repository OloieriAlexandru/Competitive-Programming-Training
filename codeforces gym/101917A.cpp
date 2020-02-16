#include <bits/stdc++.h>
#define nmax 1000005
#define mod 1000000007
#define lld long long
using namespace std;
lld dp[nmax];
int main()
{
    int t, a;
    dp[0] = 1;
    for (int i=1;i<=1000000;++i){
        for (int j=1;j<=8;++j){
            if (i-j<0){
                break;
            }
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cin>>t;
    while(t--){
        cin>>a;
        a /= 3;
        cout<<dp[a]<<'\n';
    }
    return 0;
}
