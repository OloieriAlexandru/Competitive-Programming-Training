#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
struct query
{
    int type, p, v;
} qu[nmax];
int n, q, a[nmax], act, cnt[nmax], maxx, ans;
unordered_map<int,int> mp;
void addToMap(int x)
{
    if (!mp.count(x))
        mp[x] = ++act;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        mp.clear();
        act = 0;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d",&a[i]);
            if (a[i])
                addToMap(a[i]);
        }
        for (int i=1; i<=q; ++i)
        {
            scanf("%d",&qu[i].type);
            if (qu[i].type == 1)
            {
                scanf("%d %d",&qu[i].p,&qu[i].v);
                if (qu[i].v) addToMap(qu[i].v);
            }
        }
        maxx = mp.size();
        ans = 0;
        for (int i=1; i<=n; ++i)
            if (a[i])
            {
                a[i] = mp[a[i]];
                ++cnt[a[i]];
                if (cnt[a[i]] == 1)
                    ++ans;
            }
        for (int i=1; i<=q; ++i)
        {
            if (qu[i].type == 1)
            {
                qu[i].v = mp[qu[i].v];
                if (a[qu[i].p])
                {
                    --cnt[a[qu[i].p]];
                    if (!cnt[a[qu[i].p]]) --ans;
                }
                if (qu[i].v)
                {
                    ++cnt[qu[i].v];
                    if (cnt[qu[i].v] == 1) ++ans;
                }
                a[qu[i].p] = qu[i].v;
            }
            else printf("%d\n", ans);
        }
        for (int i=1;i<=maxx;++i)
            cnt[i] = 0;
    }
    return 0;
}
