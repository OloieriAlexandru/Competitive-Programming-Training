#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, x, ans, aint[4*nmax];
void update(int nod, int st, int dr, int poz, int x)
{
    if (st == dr)
    {
        aint[nod] = x;
        return;
    }
    int m = (st + dr) / 2;
    if (poz <= m)
        update(nod<<1,st,m,poz,x);
    else
        update(nod<<1|1,m+1,dr,poz,x);
    if (aint[nod<<1] > aint[nod<<1|1])
        aint[nod] = aint[nod<<1];
    else
        aint[nod] = aint[nod<<1|1];
}
int query(int nod, int st, int dr, int x, int y)
{
    if (x > y) return 0;
    if (x <= st && dr <= y)
        return aint[nod];
    int m = (st + dr) / 2;
    int ret = 0;
    if (x <= m)
        ret = query(nod<<1,st,m,x,y);
    if (y > m)
        ret = max(ret, query(nod<<1|1,m+1,dr,x,y));
    return ret;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        int maxx = query(1,1,n,1,x-1);
        ans = max(ans, maxx+1);
        update(1,1,n,x,maxx+1);
    }
    cout<<ans<<'\n';
    return 0;
}
