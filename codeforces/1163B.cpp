#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
struct aintNode
{
    int minn, maxx;
    int cntmin, cntmax;
};
aintNode aint[nmax*4];
int mi, ma, n, nn, ans = 1, a[nmax], cnmi, cnma;
void updateNode(int nod)
{
    if (aint[nod<<1].maxx > aint[nod<<1|1].maxx)
    {
        aint[nod].maxx = aint[nod<<1].maxx;
        aint[nod].cntmax = aint[nod<<1].cntmax;
    }
    else
    if (aint[nod<<1].maxx < aint[nod<<1|1].maxx)
    {
        aint[nod].maxx = aint[nod<<1|1].maxx;
        aint[nod].cntmax = aint[nod<<1|1].cntmax;
    }
    else
    {
        aint[nod].maxx = aint[nod<<1].maxx;
        aint[nod].cntmax = aint[nod<<1|1].cntmax + aint[nod<<1].cntmax;
    }

    if (aint[nod<<1].minn < aint[nod<<1|1].minn)
    {
        aint[nod].minn = aint[nod<<1].minn;
        aint[nod].cntmin = aint[nod<<1].cntmin;
    }
    else
    if (aint[nod<<1].minn > aint[nod<<1|1].minn)
    {
        aint[nod].minn = aint[nod<<1|1].minn;
        aint[nod].cntmin = aint[nod<<1|1].cntmin;
    }
    else
    {
        aint[nod].minn = aint[nod<<1].minn;
        aint[nod].cntmin = aint[nod<<1|1].cntmin + aint[nod<<1].cntmin;
    }
}
void update(int nod, int st, int dr, int x)
{
    if (st == dr)
    {
        if (aint[nod].minn == 999999999)
            aint[nod].minn = 1;
        else
            ++aint[nod].minn;
        ++aint[nod].maxx;
        aint[nod].cntmin = aint[nod].cntmax = 1;
        return;
    }
    int m = (st + dr) / 2;
    if (x <= m)
        update(nod<<1,st,m,x);
    else
        update(nod<<1|1,m+1,dr,x);
    updateNode(nod);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        nn = max(nn, a[i]);
    }
    for (int i=1;i<=4*nn;++i)
        aint[i].minn = 999999999;
    for (int i=1;i<=n;++i)
    {
        update(1,1,nn,a[i]);
        mi = aint[1].minn;
        ma = aint[1].maxx;
        cnmi = aint[1].cntmin;
        cnma = aint[1].cntmax;
        if (((mi * cnmi + ma * cnma == i && mi != ma) || (mi * cnmi == i && mi == ma))&& ((mi == ma && cnmi == cnma && mi == i) || (mi == ma && cnmi == cnma && mi == 1) || (ma - 1 == mi && cnma == 1)|| (mi - 1 == 0 && cnmi == 1)))
            ans = i;
    }
    cout<<ans<<'\n';
    return 0;
}
