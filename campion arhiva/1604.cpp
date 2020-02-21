#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 2222
#define lld long long
#define ld long double
#define pb push_back
using namespace std;

int n;
char s[nmax];

bitset<256> parseInterval(char *&str){
    bitset<256> res;
    if (!(*str)){
        return res;
    }
    bool closed1 = false, closed2 = false;
    int num1, num2;
    if (*str == '('){
        closed1 = true;
    }
    ++str;
    num1 = atoi(str);
    while (*str && *str != ','){
       ++str;
    }
    ++str;
    num2 = atoi(str);
    while (*str && *str != ')' && *str != ']'){
        ++str;
    }
    if (*str == ')'){
        closed2 = true;
    }
    ++str;
    for (int i=num1+closed1;i<=num2-closed2;++i){
        res.set(i);
    }
    return res;
}

bitset<256> parseIntersection(char *&str){
    bitset<256> t1 = parseInterval(str);
    while (*str && *str == 'n'){
        ++str;
        bitset<256>t2 = parseInterval(str);
        t1 = t1 & t2;
    }
    return t1;
}

bitset<256> parseReunionDifference(char *&str){
    bitset<256> t1 = parseIntersection(str);
    while (*str && (*str == 'u' || *str == '-')){
        bool sub = (*str == '-' ? true : false);
        ++str;
        bitset<256> t2 = parseIntersection(str);
        if (sub){
            t1 = t1 & ~t2;
        } else {
            t1 = t1 | t2;
        }
    }
    return t1;
}

int main()
{
    freopen("opmult.in","r",stdin);
    freopen("opmult.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        bitset<256> bit;

        char *p = s;
        bit = parseReunionDifference(p);

        if (bit.test(n)){
            cout<<"DA\n";
        } else {
            cout<<"NU\n";
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
5 mar 2016, 22:23
10 puncte
#include <fstream>
#include <stdlib.h>
#include <cstring>
#define LMAX 2100
#define NMAX 400

using namespace std;
ifstream fin("opmult.in");
ofstream fout("opmult.out");

void copiez(int i,int v[],int& lg);
int rezulta(int a, int b, int c);


char s[LMAX];
int n, x, cif, lg, cx, act;
int ok1, ok2;
int st, dr;
int m=1,nn=1;
int op[NMAX], este[NMAX];

int main()
{
int k, i, j;
char c;
fin>>n;fin.get(c);
for (k=1;k<=n;k++)
     {
      fin.getline(s,LMAX);
      x=atoi(s);
      cx=x;
      cif=0;
      while (cx>0) {cif++;cx=cx/10;}
      lg=strlen(s);
      for (i=cif+1;i<lg;i++)
           {
            if (s[i]=='(') ok1=1; else ok1=0; i++;
            st=atoi(s+i);
            while (s[i]!=',')i++; i++;
            dr=atoi(s+i); i++;
            if (s[i]==')') ok2=1; else ok2=0;
            if (ok1)st++; if (ok2)dr--; i++;
            if (x>=st&&x<=dr)este[nn]=1; else este[nn]=0; nn++;
            if (s[i]=='n')
                op[m]=1;
                else
                if (s[i]=='u')
                    op[m]=2;
                    else
                    op[m]=3;

            m++;
           }
      nn--;
      act=1;
      op[nn]=0;
      m=nn-1;
      for (i=1;i<=m;i++)
           if (op[i]==1)
               {
                este[i]=rezulta(este[i],este[i+1],op[i]);
                copiez(i,op,m);
                copiez(i+1,este,nn);
               }
      for (i=1,j=2;i<=m;i++,j++)
           este[1]=rezulta(este[1],este[j],op[i]);
      if (este[1])
          fout<<"DA\n";
          else
          fout<<"NU\n";
     }
fin.close();
fout.close();
return 0;
}

int rezulta(int a, int b, int c)
    {
     if (c==1)
         return a==1&&b==1;
         else
         if (c==2)
             return a==1||b==1;
     return b!=1;
    }

void copiez(int i,int v[],int& lg)
    {
     for (;i<lg;i++)
          v[i]=v[i+1];
     v[lg]=0;
     lg--;
    }

*/
