#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define nmax 100005
using namespace std;
int ans[nmax], minn[nmax];
int t, n, x, y;
vector<pair<pii,int>>v;
bool cmp(pair<pii,int> a, pair<pii,int> b)
{
    return a.first.second < b.first.second;
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        v.clear();
        for (int i=1;i<=n;++i)
        {
            scanf("%d %d",&x,&y);
            v.push_back(mp(mp(x,y),i));
        }
        bool ok = true;
        sort(v.begin(), v.end(), cmp);
        minn[n] = 999999999;
        for (int i=n-1;i>=0;--i)
            minn[i] = min(v[i].first.first, minn[i+1]);
        int maxx = v[0].first.second;
        int i;
        for (i=0;i<v.size();++i)
        {
            if (minn[i] > maxx)
                break;
            ans[v[i].second] = 1;
            maxx = max(v[i].first.second, maxx);
        }
        if (i == v.size()) ok = false;
        else
        {
            while (i < v.size())
            {
                ans[v[i].second] = 2;
                ++i;
            }
        }
        if (!ok)
        {
            printf("-1\n");
            for (int i=1;i<=n;++i)
                ans[i] = 0;
            continue;
        }
        for (int i=1;i<=n;++i)
            printf("%d ", ans[i]), ans[i] = 0;
        printf("\n");
    }
    return 0;
}
