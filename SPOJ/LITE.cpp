#include <bits/stdc++.h>
#define LMAX 100010

using namespace std;

int n, m;
int tip, x, y;

int AI[4*LMAX];
bool lazy[4*LMAX];

void push(int nod, int x, int y)
{
    if (lazy[nod])
    {
        AI[nod]=abs(AI[nod]-(y-x+1));
        lazy[nod]=0;
        if (x!=y)
            lazy[nod*2]=1-lazy[nod*2],lazy[nod*2+1]=1-lazy[nod*2+1];
    }
}

void update(int nod, int x, int y, int st, int dr)
{
    push(nod, x, y);
    if (x>y||dr<x||st>y) return ;
    if (st<=x&&y<=dr)
    {
        if (x!=y)
        {
            AI[nod]=(y-x+1)-AI[nod];
            lazy[nod*2]=1-lazy[nod*2];
            lazy[nod*2+1]=1-lazy[nod*2+1];
            return ;
        }
        else
        AI[nod]=1-AI[nod];
        return ;
    }
    int m=(x+y)/2;
    update(nod*2,x,m,st,dr);
    update(nod*2+1,m+1,y,st,dr);
    AI[nod]=AI[nod*2+1]+AI[nod*2];
}

int query(int nod, int x, int y, int st, int dr)
{
    push(nod, x, y);
    if (x>y||dr<x||st>y) return 0;
    if (st<=x&&y<=dr)
    {
        return AI[nod];
    }
    int rez=0;
    int m=(x+y)/2;
    rez+=query(nod*2, x, m, st, dr);
    rez+=query(nod*2+1,m+1,y,st,dr);
    return rez;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&tip,&x,&y);
        if (!tip)
        {
            update(1,1,n,x,y);
        }
        else
        {
            printf("%d\n",query(1,1,n,x,y));
        }
    }
    return 0;
}