#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, nr, x;
set<int>setts[nmax];
vector<int>fathers[nmax];
vector<int>childs[nmax];
vector<pair<int,int>>ans;
vector<pair<int,int>>dgs;
int sub[nmax], cnt, maxx, root;
bool used[nmax], usedThisTime[nmax];
vector<int>g[nmax];
void dfs1(int k, int lst)
{
    ++cnt;
    for (auto x:g[k])
    {
        if (x == lst) continue;
        dfs1(x, k);
    }
}
set<int> dfs2(int k, int lst)
{
    set<int> ret;
    for (auto x:g[k])
    {
        if (x == lst) continue;
        auto v = dfs2(x, k);
        for (auto y:v)
            ret.insert(y);
    }
    for (auto x:childs[k])
        if (!ret.count(x))
    {
        cout<<"NO\n";
        exit(0);
    }
    for (auto x:ret)
        if (!setts[k].count(x))
    {
        cout<<"NO\n";
        exit(0);
    }
    ret.insert(k);
    return ret;
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&nr);
        if (nr > maxx)
            maxx = nr, root = i;
        dgs.push_back(make_pair(nr, i));
        for (int j=1; j<=nr; ++j)
        {
            scanf("%d",&x);
            setts[i].insert(x);
            fathers[x].push_back(i);
            childs[i].push_back(x);
        }
    }
    while (true)
    {
        sort(dgs.begin(), dgs.end());
        if (dgs[0].first != 0)
            break;
        memset(sub, 0, sizeof(sub));
        memset(usedThisTime, 0, sizeof(usedThisTime));
        for (int i=0; i<dgs.size(); ++i)
        {
            if (dgs[i].first != 0) break;
            for (auto x : fathers[dgs[i].second])
                ++sub[x];
            for (auto x: childs[dgs[i].second])
            {
                if (!used[x])
                {
                    used[x] = true;
                    ans.push_back(make_pair(dgs[i].second, x));
                    g[x].push_back(dgs[i].second);
                    g[dgs[i].second].push_back(x);
                }
            }
            dgs[i].first = 99999999;
        }
        for (int i=0; i<dgs.size(); ++i)
            if (sub[dgs[i].second])
                dgs[i].first -= sub[dgs[i].second];
    }
    cnt = 0;
    dfs1(root, -1);
    if (cnt != n)
    {
        cout<<"NO\n";
        return 0;
    }
    dfs2(root, -1);
    if (ans.size() + 1 == n)
    {
        printf("YES\n");
        for (auto x:ans)
            printf("%d %d\n", x.first, x.second);
        printf("\n");
    }
    else
        printf("NO\n");
    return 0;
}
