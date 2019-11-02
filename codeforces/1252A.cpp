#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int ans[nmax], n, x;
int main()
{
    vector<pair<int,int>>v;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    int nr = n;
    for (auto x:v){
        ans[x.second] = nr--;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}
