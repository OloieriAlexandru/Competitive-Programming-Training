#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, m, a[nmax], ans[nmax], l, anss, x, y;
vector<pair<pair<int,int>,int>>queries;
unordered_map<int,int>fv;
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    if (a.first.first/l == b.first.first/l)
        return a.first.second < b.first.second;
    return a.first.first/l < b.first.first/l;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;++i)
    {
        scanf("%d %d",&x,&y);
        --x, --y;
        queries.push_back(make_pair(make_pair(x,y),i));
    }
    l = sqrt(n);
    if (!l) l = 1;
    sort(queries.begin(), queries.end(), cmp);
    int mo_left = 0, mo_right = -1;
    for (int i=0; i<queries.size(); ++i)
    {
        int lft = queries[i].first.first;
        int rgh = queries[i].first.second;
        while (mo_right<rgh)
        {

            ++mo_right;
            ++fv[a[mo_right]];
            if (fv[a[mo_right]]==a[mo_right])
                ++anss;
            else
            if (fv[a[mo_right]]-1==a[mo_right])
                --anss;
        }
        while (mo_left<lft)
        {
            if (fv[a[mo_left]]==a[mo_left])--anss;
            else
            if (fv[a[mo_left]]-1==a[mo_left])++anss;
            --fv[a[mo_left]];
            ++mo_left;
        }
        while (mo_left>lft)
        {
            --mo_left;
            ++fv[a[mo_left]];
            if(fv[a[mo_left]]==a[mo_left])
                ++anss;
            else
            if (fv[a[mo_left]]-1==a[mo_left])
                --anss;
        }
        while (mo_right>rgh)
        {
            if (fv[a[mo_right]]==a[mo_right])--anss;
            else
            if (fv[a[mo_right]]-1==a[mo_right])++anss;
            --fv[a[mo_right]];
            --mo_right;
        }
        ans[queries[i].second] = anss;
    }
    for (int i=1;i<=m;++i)
        printf("%d\n", ans[i]);
    return 0;
}
