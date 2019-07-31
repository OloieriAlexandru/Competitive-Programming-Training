#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, q, x, y, z, l, r;
char s[nmax];
int aint[26][4*nmax], lazy[26][4*nmax], cnt[26];
void push(int nod, int st, int dr, int arb)
{
    if (lazy[arb][nod])
    {
        lazy[arb][nod<<1] = lazy[arb][nod], lazy[arb][nod<<1|1] = lazy[arb][nod];
        aint[arb][nod] = (lazy[arb][nod]-1) * (dr - st + 1);
        lazy[arb][nod] = 0;
    }
}
int query(int nod, int st, int dr, int x, int y, int arb)
{
    push(nod, st, dr, arb);
    if (x <= st && dr <= y)
        return aint[arb][nod];
    int ret = 0, m = (st + dr) / 2;
    if (x <= m)
        ret += query(nod<<1,st,m,x,y,arb);
    if (y > m)
        ret += query(nod<<1|1,m+1,dr,x,y,arb);
    return ret;
}
void update(int nod, int st, int dr, int x, int y, int add, int arb)
{
    push(nod, st, dr, arb);
    if (st > dr || x > dr || y < st) return;
    if (x <= st && dr <= y)
    {
        aint[arb][nod] = (add-1) * (dr - st + 1);
        lazy[arb][nod<<1] = add;
        lazy[arb][nod<<1|1] = add;
        return;
    }
    int m = (st + dr) / 2;
    update(nod<<1,st,m,x,y,add,arb);
    update(nod<<1|1,m+1,dr,x,y,add,arb);
    aint[arb][nod] = aint[arb][nod<<1] + aint[arb][nod<<1|1];
}
int main()
{
    cin>>n>>q;
    cin>>s;
    for (int i=0; i<n; ++i)
    {
        s[i] -= 'a';
        update(1,1,n,i+1,i+1,2,s[i]);
    }
    for (int i=1; i<=q; ++i)
    {
        cin>>x>>y>>z;
        l = x, r = y;
        for (int j=0; j<26; ++j)
            cnt[j] = query(1,1,n,x,y,j);
        for (int j=0; j<26; ++j)
            update(1,1,n,x,y,1,j);
        if (z == 1)
            for (int j=0; j<26; ++j)
            {
                if (!cnt[j]) continue;
                update(1,1,n,l,l+cnt[j]-1,2,j);
                l += cnt[j];
            }
        else
            for (int j=0; j<26; ++j)
            {
                if (!cnt[j]) continue;
                update(1,1,n,r-cnt[j]+1,r,2,j);
                r -= cnt[j];
            }
    }
    for (int i=1; i<=n; ++i)
    {
        int j=0, fv;
        while (j < 26)
        {
            fv = query(1,1,n,i,i,j);
            if (fv) break;
            ++j;
        }
        cout<<(char)(j+'a');
    }
    cout<<'\n';
    return 0;
}
