#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax 200011
#define lld long long
#define inf 9999999999999999LL
using namespace std;
int a[nmax];
lld dp[nmax], st[nmax];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    st[1] = a[1];
    for (int i=2;i<=n;++i){
        st[i] = st[i-2] + a[i];
    }
    for (int i=2;i<=n;++i){
        if (i % 2){
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        } else {
            dp[i] = a[i] + dp[i-2];
            dp[i] = max(dp[i], st[i-1]);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
