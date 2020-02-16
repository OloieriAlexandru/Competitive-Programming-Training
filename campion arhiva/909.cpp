#include <bits/stdc++.h>
#define nmax 105
#define pii pair<int,int>
#define mp make_pair
#define inf 999999999
using namespace std;
int a[nmax][nmax], n, s, ans[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool inq[nmax][nmax];
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=n;
}
void lee(int l, int c){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            ans[i][j] = -1;
        }
    }
    queue< pii >q;
    ans[l][c] = s - a[1][1];
    q.push(mp(l,c));
    int i, j;
    pii act;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        inq[i][j] = false;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (ans[i+dl[k]][j+dc[k]] < ans[i][j] - a[i+dl[k]][j+dc[k]] && ans[i][j] >= a[i+dl[k]][j+dc[k]]){
                ans[i+dl[k]][j+dc[k]] = ans[i][j] - a[i+dl[k]][j+dc[k]];
                if (!inq[i+dl[k]][j+dc[k]]){
                    q.push(mp(i+dl[k],j+dc[k]));
                    inq[i+dl[k]][j+dc[k]] = true;
                }
            }
        }
    }
}
int main()
{
    freopen("taxe1.in","r",stdin);
    freopen("taxe1.out","w",stdout);
    scanf("%d %d",&s,&n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    lee(1,1);
    if (ans[n][n] == -1){
        printf("-1\n");
    } else {
        printf("%d\n", ans[n][n]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
50p
6 oct 2016, 10:26

#include <fstream>
#define INFINIT 9999999
#define LMAX 105

using namespace std;
ifstream fin("taxe1.in");
ofstream fout("taxe1.out");

struct element_m{
    int l, c, s;
}; element_m e[LMAX*LMAX];

void citire();
void LEE();
void afisare();
void tot_INFINIT();

bool interior(int i, int j);
bool ebun(int i, int j, int sum);


int dl[]={1,0};
int dc[]={0,1};

int a[LMAX][LMAX], p[LMAX][LMAX];

int n, s;

int main()
{
citire();
tot_INFINIT();
LEE();
afisare();
fin.close();
fout.close();
return 0;
}

void tot_INFINIT()
    {
     int i, j;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
               p[i][j]=INFINIT;
    }

void afisare()
    {
     if (p[n][n]==0)
         fout<<-1<<'\n';
         else
         if (s-p[n][n]>0)
            fout<<s-p[n][n]<<'\n';
            else fout<<-1<<'\n';
    }

void citire()
    {
    int i, j;
    fin>>s>>n;
    for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
              fin>>a[i][j];
    }

void LEE()
    {
     int prim=0, ultim=0, k, pret_pus;
     element_m x;
     p[1][1]=a[1][1];
     e[prim].l=1;
     e[prim].c=1;
     e[prim].s=a[1][1];
     while (prim<=ultim)
        {
         x=e[prim++];
         for (k=0;k<2;k++)
              if (ebun(x.l+dl[k],x.c+dc[k],x.s))
                  {
                  pret_pus=x.s+a[x.l+dl[k]][x.c+dc[k]];
                  //if (pret_pus<p[x.l+dl[k]][x.c+dc[k]])//||p[x.l+dl[k]][x.c+dc[k]]==0)
                      p[x.l+dl[k]][x.c+dc[k]]=pret_pus;
                       ultim++;
                       e[ultim].l=x.l+dl[k];
                       e[ultim].c=x.c+dc[k];
                       e[ultim].s=pret_pus;
                  }

        }
    }

bool ebun(int i, int j, int sum)
    {
     if (interior(i,j))
         if ((sum+a[i][j]<=s)&&(sum+a[i][j]<p[i][j]))
              return 1;
     return 0;
    }

bool interior(int i, int j)
    {
     return i<=n&&j<=n;
    }
*/
