#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 100005
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, a[nmax], x, y;
vector<pii>v;
int ans[nmax];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=0;i<m;++i){
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end());
    vector<int>bs;
    for (auto x:v){
        bs.pb(x.first);
    }
    ans[0] = v[0].second;
    for (int i=1;i<m;++i){
        ans[i] = ans[i-1] + v[i].second;
    }
    for (int i=1;i<=n;++i){
        auto it = upper_bound(bs.begin(),bs.end(),a[i]);
        cout<<ans[it-bs.begin()-1]<<' ';
    }
    cout<<'\n';
    return 0;
}
