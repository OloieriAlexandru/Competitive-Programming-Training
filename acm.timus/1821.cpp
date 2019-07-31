#include <bits/stdc++.h>
#define lld long long
using namespace std;
vector<string>ans;
lld read(string& name)
{
    int a, b, c;
    char ch1, ch2;
    cin>>name>>a>>ch1>>b>>ch2>>c;
    return 1LL * a * 600 + 1LL * b * 10 + c;
}
vector<pair<pair<int,int>,string>>v;
int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i=1;i<=n;++i)
    {
        string nm;
        int act = read(nm) + (i-1) * 300;
        v.push_back(make_pair(make_pair(act, act - (i-1)*300),nm));
    }
    sort(v.begin(), v.end());
    int bst = 999999999;
    for (int i=0;i<v.size();++i)
    {
        if (bst < v[i].first.second) continue;
        bst = v[i].first.second;
        ans.push_back(v[i].second);
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(), ans.end());
    for (auto x:ans)
        cout<<x<<'\n';
    return 0;
}
