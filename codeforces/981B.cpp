#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    map<int,int>mp;
    long long ans = 0;
    cin>>n;
    for (int i=1;i<=n;++i){
        int x, y;
        cin>>x>>y;
        mp[x]=max(mp[x],y);
    }
    cin>>n;
    for (int i=1;i<=n;++i){
        int x, y;
        cin>>x>>y;
        mp[x]=max(mp[x],y);
    }
    for (auto x:mp){
        ans += x.second;
    }
    cout<<ans<<'\n';
    return 0;
}
