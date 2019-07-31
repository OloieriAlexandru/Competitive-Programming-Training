#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<pair<int,int>>v;
vector<int>ans;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        if (x > y) swap(x, y);
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), cmp);
    int maxx = v[0].second;
    for (int i=1;i<v.size();++i)
    {
        if (v[i].first > maxx)
        {
            ans.push_back(maxx);
            maxx = v[i].second;
        }
    }
    ans.push_back(maxx);
    printf("%d\n", ans.size());
    for (auto x:ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}
