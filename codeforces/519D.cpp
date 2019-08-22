#include <bits/stdc++.h>
#define nmax 26
using namespace std;
long long cost[nmax], ans, sact, nw;
map<long long,int>mp[nmax];
string s;
int main()
{
    for (int i=0;i<nmax;++i)
        cin>>cost[i];
    cin>>s;
    for (int i=0;i<s.size();++i)
    {
        nw = s[i] - 'a';
        ans += mp[nw][sact];
        sact += cost[nw];
        ++mp[nw][sact];
    }
    cout<<ans<<'\n';
    return 0;
}
