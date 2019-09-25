#include <bits/stdc++.h>
#define nmax 200005
#define pii pair<int,int>
using namespace std;
int n, m, x, y;
bool ok;
vector<pair<pii,int>>v;
vector<int>ans;
bool cmp(pair<pii,int> a, pair<pii,int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(make_pair(x,y),i));
    }
    sort(v.begin(), v.end(), cmp);
    if (v[0].first.first != 1)
    {
        cout<<"NO\n";
        return 0;
    }
    int ptr = 0, cur = 1, max_r = 0;
    bool ok = true;
    while (cur <= m)
    {
        int idx = -1;
        while (ptr < n && v[ptr].first.first <= cur)
        {
            if (v[ptr].first.second > max_r)
            {
                max_r = v[ptr].first.second;
                idx = v[ptr].second;
            }
            ++ptr;
        }
        if (idx == -1)
        {
            ok = false;
            break;
        }
        ans.push_back(idx);
        cur = max_r + 1;
    }
    if (ok)
    {
        printf("YES\n");
        printf("%d\n", ans.size());
        for (auto x:ans)
            printf("%d ", x);
        printf("\n");
    }
    else
        printf("NO\n");
    return 0;
}
