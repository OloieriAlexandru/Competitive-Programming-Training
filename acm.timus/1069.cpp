#include <bits/stdc++.h>
#define nmax 7505
using namespace std;
int fv[nmax], maxx, n, a[nmax];
vector<int>g[nmax];
struct node
{
    int fv, node;
};
node aint[4*nmax];
void updateNode(int nod)
{
    if (aint[nod<<1].fv < aint[nod<<1|1].fv)
    {
        aint[nod].fv = aint[nod<<1].fv;
        aint[nod].node = aint[nod<<1].node;
    }
    else
    if (aint[nod<<1].fv > aint[nod<<1|1].fv)
    {
        aint[nod].fv = aint[nod<<1|1].fv;
        aint[nod].node = aint[nod<<1|1].node;
    }
    else
    {
        aint[nod].fv = aint[nod<<1].fv;
        aint[nod].node = min(aint[nod<<1].node, aint[nod<<1|1].node);
    }
}
void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod].fv = fv[st];
        aint[nod].node = st;
        return;
    }
    int m = (st + dr) / 2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    updateNode(nod);
}
void update(int nod, int st, int dr, int x)
{
    if (st == dr)
    {
        --aint[nod].fv;
        if (aint[nod].fv == 0)
            aint[nod].fv = 999999999;
        return;
    }
    int m = (st + dr)/2;
    if (x <= m)
        update(nod<<1,st,m,x);
    else
        update(nod<<1|1,m+1,dr,x);
    updateNode(nod);
}
int query(int nod, int st, int dr)
{
    return aint[1].node;
}
int main()
{
    while(cin>>a[++n])
    {
        ++fv[a[n]];
        maxx = max(a[n], maxx);
    }
    for (int i=1;i<maxx;++i)
        ++fv[i];
    build(1,1,maxx);
    for (int i=1;i<n;++i)
    {
        int nd = query(1,1,maxx);
        g[nd].push_back(a[i]);
        g[a[i]].push_back(nd);
        update(1,1,maxx,nd);
        update(1,1,maxx,a[i]);
    }
    for (int i=1;i<=maxx;++i)
    {
        sort(g[i].begin(), g[i].end());
        cout<<i<<": ";
        for (auto x:g[i])
            cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}
