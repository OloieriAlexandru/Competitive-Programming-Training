#include <bits/stdc++.h>
#define LMAX 100123

using namespace std;

vector<int> numere;

int AI[4*LMAX];
int valAI[4*LMAX];

struct query{
    int tip;
    int valoare;
};
vector<query> Q;
query acttt;

struct element{
    void reset()
    {
        nr=0;
        val=0;
    }
    int nr, val;
};
vector <element> V;
element act;
int avem;
int n, nr;
char c;

int maxim;

int cmmdc(int x, int y)
{
    int d;
    while (y)
    {
        d=x%y;
        x=y;
        y=d;
    }
    return x;
}

int query(int nod, int st, int dr, int x, int y)
{
    if (x<=st&&dr<=y)
    {
        return valAI[nod];
    }
    int m;
    int rez1=-1, rez2=-1;
    m=(st+dr)/2;
    if (x<=m)
        rez1=query(nod*2,st,m,x,y);
    if (y>m)
        rez2=query(nod*2,m+1,dr,x,y);
    if (rez1==-1)
        return rez2;
    if (rez2==-1)
        return rez1;
    return (cmmdc(rez1,rez2));
}

void update(int nod, int st, int dr, int poz, int val)
{
    if (st==dr)
    {
        AI[nod]+=val;
        if (!AI[nod])
            valAI[nod]=1;
            else
            valAI[nod]=V[poz-1].val;
        return ;
    }
    int m=(st+dr)/2;
    if (poz<=m)
        update(nod*2,st,m,poz,val);
        else update(nod*2+1,m+1,dr,poz,val);
    if (AI[nod*2]&&AI[nod*2+1])//stanga e in colectie, dreapta e in colectie
        {
        AI[nod]=1;
        valAI[nod]=cmmdc(valAI[nod*2],valAI[nod*2+1]);
        }
        else if (AI[nod*2])
        {
         AI[nod]=1;
         valAI[nod]=valAI[nod*2];
        }
        else if (AI[nod*2+1])
        {
         AI[nod]=1;
         valAI[nod]=valAI[nod*2+1];
        }
        else
        {
         AI[nod]=0;
         valAI[nod]=1;
        }
}

int cb(int x)
{
    int st=0, dr=V.size()-1;
    while (st<=dr)
    {
        int m=(st+dr)/2;
        if (V[m].val==x)
            return m;
            else if (V[m].val>x)
                dr=m-1;
                else st=m+1;
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>c>>nr;
        numere.push_back(nr);
        if (c=='+')
            acttt.tip=1;
            else acttt.tip=0;
        acttt.valoare=nr;
        Q.push_back(acttt);
    }
    sort(numere.begin(),numere.begin()+numere.size());
    for (int i=0;i<numere.size();i++)
    {
        if (numere[i]==numere[i+1])
        {
            act.reset();
            act.nr=++avem;
            act.val=numere[i];
            while (numere[i]==numere[i+1]&&i<numere.size())
                i++;
            V.push_back(act);
        }
        else
        {
         act.reset();
         act.nr=++avem;
         act.val=numere[i];
         V.push_back(act);
        }
    }
    for (int i=0;i<Q.size();i++)
    {
        Q[i].valoare=V[cb(Q[i].valoare)].nr;
    }
    maxim=avem;
    for (int i=0;i<Q.size();i++)
    {
        if (Q[i].tip==1)
            {
             update(1,1,maxim,Q[i].valoare,+1);
            }
            else
            {
             update(1,1,maxim,Q[i].valoare,-1);
            }
        cout<<query(1,1,maxim,1,maxim)<<'\n';
    }

    return 0;
}