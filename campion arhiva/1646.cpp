#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 505
#define inf 999999999
using namespace std;
int tt, n, m, t, l, c, k, s, x, y;
int a[nmax][nmax], acc[nmax][nmax], dist[nmax][nmax];
bool panda[nmax][nmax], used[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}
bool good(int vx, int vy, int s){
    for (int i=0;i<s;++i){
        x = (1<<i)&vx;
        y = (1<<i)&vy;
        x = x ? 1 : 0;
        y = y ? 1 : 0;
        if (x+y != 1){
            return false;
        }
    }
    return true;
}
void lee(int l, int c){
    queue<pii>q;
    pii act;
    int i, j;
    q.push(mp(l,c));
    used[l][c] = true;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            dist[i][j] = inf;
        }
    }
    dist[l][c] = 0;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (used[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (!acc[i+dl[k]][j+dc[k]]){
                continue;
            }
            used[i+dl[k]][j+dc[k]] = true;
            dist[i+dl[k]][j+dc[k]] = dist[i][j] + 1;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int main()
{
    freopen("panda.in","r",stdin);
    freopen("panda.out","w",stdout);
    scanf("%d",&tt);
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&l,&c,&k,&s);
    for (int i=1;i<=t;++i){
        scanf("%d %d",&x,&y);
        panda[x][y] = true;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            if (good(a[i][j],k,s)){
                acc[i][j] = true;
            }
        }
    }
    if (tt == 1){
        int ans = -1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (acc[i][j]){
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    } else {
        lee(l,c);
        int ans = inf, ans2 = 0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (!panda[i][j]){
                    continue;
                }
                if (!acc[i][j]){
                    continue;
                }
                ans = min(ans, dist[i][j]);
            }
        }
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (!panda[i][j]){
                    continue;
                }
                if (!acc[i][j]){
                    continue;
                }
                if (dist[i][j] == ans){
                    ++ans2;
                }
            }
        }
        printf("%d %d\n", ans, ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 mar 2016, 20:51

#include <cstdio>
#include <cstring>
#include <stdlib.h>
#define LMAX 502
#define LMAX2 10

using namespace std;
FILE *fin=fopen("panda.in","r");
FILE *fout=fopen("panda.out","w");

int n, m, l, c, k, s, ok, nr, tmin;
int a[LMAX][LMAX];

int b2k[LMAX2], b2x[LMAX2];

struct celula
{
    int l;
    int c;
}; celula cel[LMAX*LMAX], act;

int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void binar(int a,int* v,int lgm);
void citire(int& p);
void citireparsare();
void LEE();

int complementare(int a1[],int a2[]);
int accesibile();
int interior(int i,int j);

int main()
{
int p;
citire(p);
binar(k,b2k,s);
citireparsare();
switch (p)
    {
     case 1:{
     fprintf(fout,"%d\n",accesibile());
     break;
     }
     case 2:{
     LEE();
     break;
     }
    }
return 0;
}

void citire(int& p)
    {
     int i, t, x, y;
     fscanf(fin,"%d",&p);
     fscanf(fin,"%d %d %d",&n,&m,&t);
     fscanf(fin,"%d %d %d %d",&l,&c,&k,&s);
     for (i=1;i<=t;i++)
          {
           fscanf(fin,"%d %d",&x,&y);
           a[x][y]=-2;
          }
     char c;
     c=fgetc(fin);
    }

void citireparsare()
    {
     char sir[5*LMAX+1];
     char *p;
     int i, j, x;
     for (i=1;i<=n;i++)
          {
           fgets(sir,5*LMAX+1,fin);
           j=0;
           p=strtok(sir," ");
           while (p)
               {
                j++;
                x=atoi(p);
                binar(x,b2x,s);
                if (complementare(b2k,b2x))
                    {if (a[i][j]==0)
                        a[i][j]=-1;}
                    else
                    a[i][j]=0;
                p=strtok(NULL," ");
               }
          }
    }

void binar(int a,int* v,int lgm)
    {
     if (lgm>0)
        {
         *(v+s)=a%2;
         binar(a/2,v-1,lgm-1);
        }
    }

int complementare(int a1[],int a2[])
    {
     int i;
     for (i=1;i<=s;i++)
          if ((!a1[i]&&!a2[i])||(a1[i]&&a2[i]))
              return 0;
     return 1;
    }

int accesibile()
    {
     int i, j, nr=0;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j]==-2||a[i][j]==-1)
                   nr++;
     return nr-1;
    }

void LEE()
    {
     int prim=0;
     int ultim=0;
     int k;
     int dlin, dcol;
     cel[0].l=l;
     cel[0].c=c;
     a[l][c]=0;
     while (prim<=ultim)
         {
          act=cel[prim];
          prim++;
          if (a[act.l][act.c]>tmin&&ok) break;
          for (k=0;k<4;k++)
              {
               dlin=act.l+dl[k];
               dcol=act.c+dc[k];
               if (interior(dlin,dcol))
                   {if (a[dlin][dcol]==-2&&!ok)
                        {ok=1;
                         tmin=a[act.l][act.c];
                        }
                    if (a[dlin][dcol]==-1||a[dlin][dcol]==-2)
                        {
                         if (a[dlin][dcol]==-2&&ok)
                             nr++;
                         a[dlin][dcol]=a[act.l][act.c]+1;
                         if (!ok)
                             {ultim++;
                             cel[ultim].l=dlin;
                             cel[ultim].c=dcol;}

                        }
                   }
              }
         }
     fprintf(fout,"%d %d\n",tmin+1,nr);
    }

int interior(int i,int j)
    {
     return i>=1 && i<=n && j>=1 && j<=m;
    }
*/
