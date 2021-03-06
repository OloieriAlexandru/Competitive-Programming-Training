#include <bits/stdc++.h>
#define inf 999999999
using namespace std;

int n, p, maxx = -inf, early = inf;
string act, ans;
map<string,int>points;
map<string,vector<pair<int,int>>>history;
vector<string>candidates;

int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>act>>p;
        points[act] += p;
        history[act].push_back(make_pair(points[act],i));
    }
    for (auto x:points)
    {
        if (x.second > maxx)
        {
            candidates.clear();
            maxx = x.second;
            candidates.push_back(x.first);
        }
        else
        if (x.second == maxx)
            candidates.push_back(x.first);
    }
    if (candidates.size() == 1)
        cout<<candidates[0]<<'\n';
    else
    {
        for (auto y:candidates)
        {
            for (auto x:history[y])
            {
                if (x.first >= maxx && x.second < early)
                    ans = y, early = x.second;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
