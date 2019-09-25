#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<pair<int,int>>a;
int n, x, af;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        a.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int>b)
    {
        return a.first > b.first;
    });
    for (int i=0; i<a.size(); ++i)
    {
        ans.push_back(a[i].second);
        af += i*a[i].first + 1;
    }
    cout<<af<<'\n';
    for (auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
