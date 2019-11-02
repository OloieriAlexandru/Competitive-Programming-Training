#include <bits/stdc++.h>
#define mod 1000000007
#define nmax 100005
using namespace std;
int n, dp[nmax];
char s[nmax];
int main()
{
    cin>>(s+1);
    n=strlen(s+1);
    dp[0]=1;
    for (int i=1;i<=n;++i){
        if (s[i]=='m'||s[i]=='w'){
            cout<<"0\n";
            return 0;
        }
        dp[i]=dp[i-1];
        if ((i>=2&&s[i]=='u'&&s[i-1]=='u')||(i>=2&&s[i]=='n'&&s[i-1]=='n')){
            dp[i]=(dp[i]+dp[i-2])%mod;
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
