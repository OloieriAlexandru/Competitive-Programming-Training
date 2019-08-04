#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, x, y, cc;
vector<pair<int,int>>g[nmax];
vector<int>dispEdges[nmax];
pair<int,int>edges[nmax];
bool usedEdges[nmax], used[nmax];
int repr[nmax];
bool added[nmax];
void dfs(int k, int lst)
{
    used[k] = true;
    for (auto x:g[k])
    {
        if (used[x.first] && x.first != lst)
        {
            if (!added[x.second])
                dispEdges[cc].push_back(x.second), added[x.second] =true;
            continue;
        }
        if (used[x.first]) continue;
        usedEdges[x.second] = true;
        dfs(x.first, k);
    }
}
vector<pair<pair<int,int>,pair<int,int>>>ans;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
    cin>>n;
    for (int i=1; i<n; ++i)
    {
        cin>>x>>y;
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        edges[i].first = x;
        edges[i].second = y;
    }
    for (int i=1; i<=n; ++i)
    {
        if (used[i]) continue;
        ++cc;
        dfs(i,-1);
        repr[cc] = i;
    }
    vector<pair<int,int>>toSort;
    for (int i=1;i<=cc;++i)
        toSort.push_back(make_pair(dispEdges[i].size(), i));
    sort(toSort.begin(), toSort.end(), cmp);
    int ind = 2;
    int act = toSort[1].second;
    for (int i=0;i<cc && ind <= cc; ++i)
    {
        if (toSort[i].second == act) continue;
        for (auto x:dispEdges[toSort[i].second])
        {
            ans.push_back(make_pair(edges[x],make_pair(edges[x].first,repr[act])));
            act = toSort[ind].second;
            ++ind;
            if (ind == cc+1) break;
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x.first.first<<' '<<x.first.second<<' '<<x.second.first<<' '<<x.second.second<<'\n';
    return 0;
}
