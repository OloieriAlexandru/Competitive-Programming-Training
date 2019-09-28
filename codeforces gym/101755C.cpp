#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int>ans;
vector<pair<pii,int>>v;
int n, x, y;
bool cmp(pair<pii,int> a, pair<pii,int> b)
{
    return a.first.second < b.first.second;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        v.pb(mp(mp(x,y),i));
    }
    sort(v.begin(),v.end(),cmp);
    ans.push_back(v[0].first.second);
    int r = v[0].first.second;
    for (int i=1;i<n;++i)
    {
        if (r < v[i].first.first)
        {
            ans.push_back(v[i].first.second);
            r = v[i].first.second;
        }
    }
    printf("%d\n", ans.size());
    for (auto x:ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}
