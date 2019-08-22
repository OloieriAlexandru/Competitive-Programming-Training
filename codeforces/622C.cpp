#include <bits/stdc++.h>
#define nmax 200005
#define mp make_pair
using namespace std;
int n, m, a[nmax], x, y, v;
struct aintNode
{
    int mi, ma, mip, mapp;
};
aintNode aint[nmax*4];
pair<int,int> minn, maxx;
void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod].mapp = aint[nod].mip = st;
        aint[nod].mi = aint[nod].ma = a[st];
        return ;
    }
    int m = (st + dr) / 2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    if (aint[nod<<1].mi <= aint[nod<<1|1].mi)
        aint[nod].mi = aint[nod<<1].mi, aint[nod].mip = aint[nod<<1].mip;
    else
        aint[nod].mi = aint[nod<<1|1].mi, aint[nod].mip = aint[nod<<1|1].mip;
    if (aint[nod<<1].ma >= aint[nod<<1|1].ma)
        aint[nod].ma = aint[nod<<1].ma, aint[nod].mapp = aint[nod<<1].mapp;
    else
        aint[nod].ma = aint[nod<<1|1].ma, aint[nod].mapp = aint[nod<<1|1].mapp;
}
pair<int,int> queryMin(int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
        return mp(aint[nod].mi, aint[nod].mip);
    int m = (st + dr) / 2;
    pair<int,int> ret, got;
    ret.first = 999999999;
    if (x <= m)
        ret = queryMin(nod<<1,st,m,x,y);
    if (y > m)
    {
        got = queryMin(nod<<1|1,m+1,dr,x,y);
        if (got.first < ret.first)
            ret = got;
    }
    return ret;
}
pair<int,int> queryMax(int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
        return mp(aint[nod].ma, aint[nod].mapp);
    int m = (st + dr) / 2;
    pair<int,int> ret, got;
    ret.first = -999999999;
    if (x <= m)
        ret = queryMax(nod<<1,st,m,x,y);
    if (y > m)
    {
        got = queryMax(nod<<1|1,m+1,dr,x,y);
        if (got.first > ret.first)
            ret = got;
    }
    return ret;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d %d",&x,&y,&v);
        minn = queryMin(1, 1, n, x, y);
        maxx = queryMax(1, 1, n, x, y);
        if (minn.first == v && maxx.first == v)
            printf("-1\n");
        else
        if (minn.first != v)
            printf("%d\n", minn.second);
        else
            printf("%d\n", maxx.second);
    }
    return 0;
}
