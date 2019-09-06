#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, x, y;
map<int,int>mp;
int a[nmax], b[nmax];
vector<pair<pair<int,int>,int>>ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        ++mp[x];
    }
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        ans.push_back(make_pair(make_pair(mp[a[i]], mp[b[i]]), i));
    }
    sort(ans.begin(), ans.end(), [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
    {
        if (a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first > b.first.first;
    });
    cout<<ans[0].second<<'\n';
    return 0;
}
