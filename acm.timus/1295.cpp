#include <bits/stdc++.h>
#define lld long long
#define mod 10000
using namespace std;
lld modPow(lld x, lld n){
    if (!n){
        return 1LL;
    }
    if ((n&1)==0){
        return modPow((x*x)%mod,n>>1);
    }
    return (x*modPow((x*x)%mod,n>>1))%mod;
}
int zeros(long long x){
    int res = 0;
    while (x){
        if (x % 10){
            break;
        }
        ++res;
        x /= 10;
    }
    return res;
}
int getAns(int x){
    lld ans = (modPow(1,x)+modPow(2,x)+modPow(3,x)+modPow(4,x))%mod;
    return zeros(ans);
}
int main()
{
    int n;
    cin>>n;
    cout<<getAns(n)<<'\n';
    return 0;
}
