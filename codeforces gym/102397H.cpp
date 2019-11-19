#include <bits/stdc++.h>
#define nmax 100005
#define mod (long long)(1e9+7)
using namespace std;
int n, a[nmax];
long long ans=0;
long long expLog(long long mul, int pw){
    if (!pw) return 1;
    if (pw&1) return (mul*expLog((mul*mul)%mod,pw>>1))%mod;
    return expLog((mul*mul)%mod,pw>>1);
}
int main()
{
    cin>>n;
    unordered_map<int,int>fv;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++fv[a[i]];
    }
    for (auto x:fv){
        ans+=(expLog(2, x.second)-1);
        ans%=mod;
    }
    ans%=mod;
    if (ans<0){
        ans=mod+ans;
    }
    cout<<ans<<'\n';
    return 0;
}
