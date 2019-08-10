#include <bits/stdc++.h>
#define nmax 405
#define inf 999999999
using namespace std;
vector<int>g1[nmax],g2[nmax];
set<pair<int,int>>st;
int n, m, x, y, sp1[nmax], sp2[nmax];
void bellman(vector<int> g[nmax], int sp[nmax])
{
    for (int i=1;i<=n;++i)
        sp[i] = inf;
    sp[1] = 0;
    queue<int>q;
    q.push(1);
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        for (auto x:g[act])
        {
            if (sp[act] + 1 < sp[x])
            {
                sp[x] = sp[act] + 1;
                q.push(x);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y;
        g1[x].push_back(y);
        g1[y].push_back(x);
        if (x > y) swap(x, y);
        st.insert(make_pair(x,y));
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            if (!st.count(make_pair(i,j)))
            {
                g2[i].push_back(j);
                g2[j].push_back(i);
            }
        }
    }
    bellman(g1, sp1);
    bellman(g2, sp2);
    if (sp1[n] == inf || sp2[n] == inf)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<max(sp1[n], sp2[n])<<'\n';
    return 0;
}
