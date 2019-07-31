#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, a, b;
vector<int> ans;
vector<pair<int,pii>> v1, v2;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a>>b;
        if (a <= b)
            v1.push_back(make_pair(i,make_pair(a,b)));
        else
            v2.push_back(make_pair(i,make_pair(a,b)));
    }
    if (v1.size() >= v2.size())
    {
        sort(v1.begin(), v1.end(), [](pair<int,pii> a, pair<int,pii> b){return a.second.first > b.second.first;});
        cout<<v1.size()<<'\n';
        for (int i=0;i<v1.size();++i)
            cout<<v1[i].first<<' ';
    }
    else
    {
        sort(v2.begin(), v2.end(), [](pair<int,pii> a, pair<int,pii> b){return a.second.second < b.second.second;});
        cout<<v2.size()<<'\n';
        for (int i=0;i<v2.size();++i)
            cout<<v2[i].first<<' ';
    }
    cout<<'\n';
    return 0;
}
