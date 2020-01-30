#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int x, n, ans;
map<int,int,greater<int>>mp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        mp.clear();
        for (int i=1;i<=n;++i){
            cin>>x;
            ++mp[x];
        }
        for (auto x:mp){
            if (x.first % 2){
                continue;
            }
            ++ans;
            mp[x.first/2] += x.second;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
