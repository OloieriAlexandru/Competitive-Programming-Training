#include <bits/stdc++.h>
#define mkp make_pair
using namespace std;
vector<pair<string,string>>coll;
map<string,int>mp;
int n, m;
string s1, s2, s;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>s1>>s2;
        mp[s1] = i-1;
        mp[s2] = i-2;
        coll.push_back(mkp(s1,s2));
    }
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        int ind = mp[s];
        s1 = coll[ind].first;
        s2 = coll[ind].second;
        if (s1.size() == s2.size() || s1.size() < s2.size())
            cout<<s1<<' ';
        else
        if (s1.size() > s2.size())
            cout<<s2<<' ';
    }
    return 0;
}
