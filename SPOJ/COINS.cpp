#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <vector>
#define mp make_pair
#define lld long long
using namespace std;

vector<pair<int,int>>tests;
vector<pair<int,lld>>ans;
unordered_map<int,lld>um;
int x, ord;

lld dpMemo(int x)
{
    if (um.count(x))
    {
        return um[x];
    }
    lld ans = 0;
    if (um.count(x/2))
    {
        ans+=um[x/2];
    }
    else
    {
        ans+=dpMemo(x/2);
    }
    if (um.count(x/3))
    {
        ans+=um[x/3];
    }
    else
    {
        ans+=dpMemo(x/3);
    }
    if (um.count(x/4))
    {
        ans+=um[x/4];
    }
    else
    {
        ans+=dpMemo(x/4);
    }
    um[x] = max(ans, (lld)x);
    return ans;
}

int main()
{
    while(cin>>x)
    {
        ++ord;
        tests.push_back(mp(x,ord));
    }
    sort(tests.begin(), tests.end());
    um[0] = 0;
    um[1] = 1;
    um[2] = 2;
    for (lld i=3;i<=1000000LL;++i)
    {
        um[i] = max(um[i/2] + um[i/3] + um[i/4], i);
    }
    for (int i=0;i<tests.size();++i)
    {
        lld an = dpMemo(tests[i].first);
        ans.push_back(mp(tests[i].second, an));
    }
    sort(ans.begin(), ans.end());
    for (auto e:ans)
    {
        cout<<e.second<<'\n';
    }
    return 0;
}
