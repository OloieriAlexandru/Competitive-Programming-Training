#include <bits/stdc++.h>
#define nmax 10005
using namespace std;
struct aintNode
{
    int val, poz;
};
aintNode aint[nmax*4];
int a[nmax], n, ans;
void updateNode(int nod)
{
    if (aint[nod<<1].val <= aint[nod<<1|1].val)
        aint[nod] = aint[nod<<1];
    else
        aint[nod] = aint[nod<<1|1];
}
void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod].poz = st;
        aint[nod].val = a[st];
        return;
    }
    int m = (st + dr) / 2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    updateNode(nod);
}
aintNode query(int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
        return aint[nod];
    int m = (st + dr) / 2;
    aintNode xx = {1999999999,1999999999}, yy = {1999999999, 1999999999};
    if (x <= m)
        xx = query(nod<<1,st,m,x,y);
    if (y > m)
        yy = query(nod<<1|1,m+1,dr,x,y);
    if (xx.val <= yy.val)
        return xx;
    return yy;
}
int calc(int st, int dr, int h)
{
    if (st > dr) return 0;
    aintNode act = query(1,1,n,st,dr);

    int ret = (dr - st + 1);

    int leftCost = calc(st,act.poz-1,act.val);
    int rightCost = calc(act.poz+1,dr,act.val);
    ret = min(ret, act.val - h + leftCost + rightCost);

    return ret;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    cout << calc(1, n, 0);
    return 0;
}
