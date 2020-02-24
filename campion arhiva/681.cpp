#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 52
#define si short int
using namespace std;

int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int n, m, best, ii, jj;
si a[nmax][nmax], replacee[nmax];
bool viz[nmax][nmax];
char ch;
queue<pii >q;
pii act;

bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}

int filll(int l, int c, short int wh){
    q.push(mp(l,c));
    viz[l][c] = true;
    int i, j, res = 1;
    while (!q.empty()){
        act = q.front();
        q.pop();
        i = act.first;
        j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] != wh){
                continue;
            }
            if (viz[i+dl[k]][j+dc[k]]){
                continue;
            }
            viz[i+dl[k]][j+dc[k]] = true;
            ++res;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
    return res;
}

void rem(int l, int c, short int wh){
    q.push(mp(l,c));
    viz[l][c] = false;
    int i, j;
    a[l][c] = 0;
    while (!q.empty()){
        act = q.front();
        q.pop();
        i = act.first;
        j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] != wh){
                continue;
            }
            if (!viz[i+dl[k]][j+dc[k]]){
                continue;
            }
            a[i+dl[k]][j+dc[k]] = 0;
            viz[i+dl[k]][j+dc[k]] = false;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}

void collapse() {
    for (int j=1;j<=m;++j){
        int cnt = 0;
        for (int i=n;i>=1;--i){
            if (a[i][j]){
                replacee[++cnt] = a[i][j];
            }
        }
        for (int i=cnt+1;i<=n;++i){
            replacee[i] = 0;
        }
        for (int i=n;i>=1;--i){
            a[i][j] = replacee[n-i+1];
        }
    }
    for (int j=m;j>=1;--j){
        int cnt = 0;
        for (int i=1;i<=n;++i){
            if (!a[i][j]){
                ++cnt;
            }
        }
        if (cnt == n){
            for (int k=j;k<m;++k){
                for (int i=1;i<=n;++i){
                    a[i][k] = a[i][k+1];
                }
            }
            --m;
        }
    }
}

int main()
{
    freopen("joc11.in","r",stdin);
    freopen("joc11.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>ch;
            if (ch == 'R'){
                a[i][j] = 1;
            } else if (ch == 'V'){
                a[i][j] = 2;
            } else {
                a[i][j] = 3;
            }
        }
    }
    int ans = 0;
    while (true){
        best = -1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                viz[i][j] = false;
            }
        }
            for (int j=1;j<=m;++j){
                for (int i=n;i>=1;--i){
                if (viz[i][j] || !a[i][j]){
                    continue;
                }
                int nw = filll(i, j, a[i][j]);
                if (nw > best){
                    best = nw;
                    ii = i, jj = j;
                }
            }
        }

        if (best < 2){
            break;
        }
        ++ans;
        rem(ii,jj,a[ii][jj]);
        collapse();
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
29 feb 2016, 19:10
10 puncte

#include <cstdio>
#define LMAX 55

using namespace std;
FILE *fin=fopen("joc11.in","r");
FILE *fout=fopen("joc11.out","w");

void citire();
void restaurez();
int interior(int i,int j);
void fill(int i,int j);
int terminat();
void citire();
int zmax(int& x,int& y,int& actmax);
void elimin(int i,int j);
int nuareelem(int m);
void sterge(int x);
void coloane();
void eliminspatii(int m);
void spatii();
int linielibera(int j);
void stergelinie(int j);

int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};

int n, m, act, cul, culoare;
int a[LMAX][LMAX];

int main()
{
int x, y, click=0, maxim;
citire();
while (!terminat())
     {
      click++;
      restaurez();
      culoare=(-1)*zmax(x,y,maxim);
      elimin(x,y);
      restaurez();
      coloane();
      spatii();
     }
fprintf(fout,"%d\n",click);
fclose(fout);
return 0;
}

void spatii()
    {
     int i;
     for (i=1;i<=m;i++)
          eliminspatii(i);
    }

void eliminspatii(int m)
    {
     int i, j, e=0;
     for (i=n;i>=1;i--)
          if (a[i][m]==0)
                {
                 e++;
                 for (j=i;j>1;j--)
                      a[j][m]=a[j-1][m];
                }
     for (i=1;i<=e;i++)
          a[i][m]=0;
    }

void coloane()
    {
     int i;
     for (i=1;i<=m;i++)
         {
          if (nuareelem(i))
              sterge(i);
         }
    }

int nuareelem(int m)
    {
     int i;
     for (i=1;i<=n;i++)
          if (a[i][m]!=0)
              return 0;
     return 1;
    }

void sterge(int x)
    {
     int i, j;
     for (i=1;i<=n;i++)
          {
           for (j=x;j<m;j++)
               a[i][j]=a[i][j+1];
           a[i][m]=0;
          }
     m--;
    }

void elimin(int i,int j)
    {
     int k;
     a[i][j]=0;
     for (k=0;k<4;k++)
          if (a[i+dl[k]][j+dc[k]]==culoare&&interior(i+dl[k],j+dc[k]))
              elimin(i+dl[k],j+dc[k]);
    }

int zmax(int& x,int& y,int& actmax)
    {
     int i, j, culmax;
     actmax=0;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j]>0)
                   {
                    act=0;
                    cul=a[i][j];
                    fill(i,j);
                    if (act>actmax)
                        {
                         actmax=act;
                         x=i;
                         y=j;
                         culmax=cul;
                        }
                   }
     return culmax;
    }

void restaurez()
    {
     int i, j;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j]<0) a[i][j]=a[i][j]*-1;
    }

int interior(int i,int j)
    {
     return i>=1&&i<=n&&j>=1&&j<=m;
    }

void fill(int i,int j)
    {
     int k;
     act++;
     a[i][j]=a[i][j]*(-1);
     for (k=0;k<4;k++)
          if (a[i+dl[k]][j+dc[k]]==cul&&interior(i+dl[k],j+dc[k]))
              fill(i+dl[k],j+dc[k]);
    }

int terminat()
    {
     int i, j;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
              if (a[i][j]>0)
                  {
                   act=0;
                   cul=a[i][j];
                   fill(i,j);
                   if (act>1) return 0;
                  }
     return 1;
    }

void citire()
    {
     int i, j;
     char c;
     fscanf(fin,"%d %d",&n,&m);fscanf(fin,"%c",&c);
     for (i=1;i<=n;i++)
          {for (j=1;j<=m;j++)
               {
                fscanf(fin,"%c",&c);
                switch (c)
                    {
                     case 'A':{
                      a[i][j]=1;break;
                     }
                     case 'V':{
                      a[i][j]=2;break;
                     }
                     case 'R':{
                      a[i][j]=3;break;
                     }
                     default:{
                      a[i][j]=0;break;
                     }
                    }
                }
          fscanf(fin,"%c",&c);}
    }
*/
