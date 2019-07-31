#include <bits/stdc++.h>
using namespace std;
int n, ln, nrv;
string s;
char lastCh;
vector<pair<string,string>>v1,v2;
vector<pair<pair<string,string>,pair<string,string>>>ans;
map<int, vector<string>>mp[26]; // au ultima litera i + 'a' si contin x caractere
map<int,vector<string>>mp2;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        ln = s.size();
        nrv = 0;
        for (int j=0; j<ln; ++j)
            if (strchr("aeiou", s[j]))
            {
                lastCh = s[j];
                ++nrv;
            }
        mp[lastCh - 'a'][nrv].push_back(s);
    }
    //cout<<"\n\n\n";
    for (int i=0; i<26; ++i)
    {
        for (auto x:mp[i])
        {
            //for (auto y:x.second)
            //    cout<<y<<' ';
            //cout<<'\n';
            if (x.second.size() % 2 == 1)
                mp2[x.first].push_back(x.second[x.second.size()-1]);
            for (int i=0; i<x.second.size(); i+=2)
            {
                if (i+1 >= x.second.size()) break;
                v1.push_back(make_pair(x.second[i], x.second[i+1]));
            }
        }
    }
    for (auto x:mp2)
    {
        for (int i=0; i<x.second.size(); i+=2)
        {
            if (i+1 >= x.second.size()) break;
            v2.push_back(make_pair(x.second[i], x.second[i+1]));
        }
    }
    int minn = min(v1.size(), v2.size());
    //cout<<v1.size()<<' '<<v2.size()<<'\n';
    for (int i=0; i<minn; ++i)
        ans.push_back(make_pair( make_pair(v2[i].first, v1[i].first),   make_pair(v2[i].second, v1[i].second) ));

    for (int i = minn;i<v1.size();i+=2)
    {
        if (i+1>=v1.size()) break;
        ans.push_back(make_pair(make_pair(v1[i+1].second, v1[i].second),make_pair(v1[i+1].first, v1[i].first)));
    }

    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
    {
        cout<<ans[i].first.first<<' '<<ans[i].first.second<<'\n';
        cout<<ans[i].second.first<<' '<<ans[i].second.second<<'\n';
    }
    return 0;
}
