#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
#define mod 1000000007
using namespace std;
char s[nmax];
int t, l, r, poz, n;
char ch;
char querry[20];
struct node
{
    lld lft, rgh;
};
lld pw[nmax];
lld poww = 31;
node aint[4*nmax];
lld h1, h2;
void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod].lft = s[st];
        aint[nod].rgh = s[st];
        return;
    }
    int m = (st + dr) / 2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    aint[nod].lft = ( aint[nod<<1].lft + pw[m+1-st] * aint[nod<<1|1].lft ) % mod;
    aint[nod].rgh = ( aint[nod<<1|1].rgh + pw[dr - m] * aint[nod<<1].rgh ) % mod;
}
void query(int nod, int st, int dr, int x, int y)
{
    if (x<=st && dr<=y)
    {
        h1 += aint[nod].lft * pw[st - x];
        h2 += aint[nod].rgh * pw[y - dr];
        h1 %= mod;
        h2 %= mod;
        return;
    }
    int m = (st + dr) / 2;
    if (x<=m)
        query(nod<<1,st,m,x,y);
    if (y>m)
        query(nod<<1|1,m+1,dr,x,y);
}
void update(int nod, int st, int dr, int poz, char ch)
{
    if (st == dr)
    {
        aint[nod].lft = ch;
        aint[nod].rgh = ch;
        return;
    }
    int m = (st + dr) / 2;
    if (poz <= m)
        update(nod<<1,st,m,poz,ch);
    else
        update(nod<<1|1,m+1,dr,poz,ch);
    aint[nod].lft = ( aint[nod<<1].lft + pw[m+1-st] * aint[nod<<1|1].lft ) % mod;
    aint[nod].rgh = ( aint[nod<<1|1].rgh + pw[dr - m] * aint[nod<<1].rgh ) % mod;
}
int main()
{
    scanf("%s",s+1);
    n = strlen(s+1);
    pw[0] = 1;
    for (int i=1;i<=n;++i)
        pw[i] = ( pw[i-1] * poww ) % mod;
    scanf("%d",&t);
    build(1,1,n);
    for (int q=1;q<=t;++q)
    {
        scanf("%s",&querry);
        if (!strcmp(querry, "change"))
        {
            scanf("%d %c",&poz,&ch);
            update(1,1,n,poz,ch);
        }
        else
        {
            scanf("%d %d",&l,&r);
            h1 = h2 = 0;
            query(1,1,n,l,r);
            if (h1 != h2)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}