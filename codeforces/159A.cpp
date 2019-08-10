#include <bits/stdc++.h>
#define nmax 2005
using namespace std;
map<string,int>mp;
map<int,string>revmp;
vector<pair<int,int>>ans;
string s1, s2;
int n, d, act,tmm, v1, v2;
vector<int> tim[nmax][nmax];
bool added[nmax][nmax];
void comp(string& s)
{
    if (!mp.count(s))
        mp[s] = ++act, revmp[act] = s;
}
int main()
{
    cin>>n>>d;
    for (int i=1; i<=n; ++i)
    {
        cin>>s1>>s2>>tmm;
        comp(s1);
        comp(s2);
        v1 = mp[s1];
        v2 = mp[s2];
        if (added[v1][v2]) continue;
        for (auto x:tim[v2][v1])
            if (tmm - x <= d && tmm - x > 0)
            {
                ans.push_back(make_pair(v1, v2));
                added[v1][v2] = added[v2][v1] = true;
                break;
            }
        tim[v1][v2].push_back(tmm);
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<revmp[x.first]<<' '<<revmp[x.second]<<'\n';
    return 0;
}
