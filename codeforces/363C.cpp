#include <bits/stdc++.h>
using namespace std;
string s;
vector<pair<int,char>>v;
int main()
{
    cin>>s;
    for (int i=0;i<s.size();++i)
    {
        int fv = 1;
        while (i < s.size()-1 && s[i] == s[i+1])
            ++fv,++i;
        v.push_back(make_pair(fv,s[i]));
    }
    for (int i=0;i<v.size();++i)
        if (v[i].first >= 3)
            v[i].first = 2;
    for (int i=1;i<v.size();++i)
        if (v[i-1].first == 2 && v[i].first == 2)
            v[i].first = 1;
    for (int i=0;i<v.size();++i)
        for (int j=0;j<v[i].first;++j)
            cout<<v[i].second;
    cout<<'\n';
    return 0;
}
