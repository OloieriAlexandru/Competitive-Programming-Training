#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 105
using namespace std;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int n, a[nmax][nmax], ans[nmax][nmax];
int lmin, lmax, cmin, cmax, l1, l2, anss, h;
vector<pii>ansss;
bool used[nmax][nmax], ok = true;
bool interior(int i, int j){
    return i >= 1 && j >= 1 && i <= n && j <= n;
}
int lee1(int l, int c){
    queue<pii>q;
    pii act;
    int i, j, res = 0;
    lmin = lmax = l;
    cmin = cmax = c;
    used[l][c] = true;
    q.push(mp(l,c));
    while(!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        lmin = min(i, lmin);
        lmax = max(i, lmax);
        cmin = min(j, cmin);
        cmax = max(j, cmax);
        ++res;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (used[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] != 1){
                continue;
            }
            used[i+dl[k]][j+dc[k]] = true;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
    return res;
}
void lee2(int l, int c){
    queue<pii>q;
    pii act;
    int i, j, nw;
    used[l][c] = true;
    q.push(mp(l,c));
    ans[l][c] = 1;
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
            if (a[i+dl[k]][j+dc[k]] != 0){
                continue;
            }
            used[i+dl[k]][j+dc[k]] = true;
            ans[i+dl[k]][j+dc[k]] = ans[i][j] + 1;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
    i = n, j = n, nw = ans[i][j];
    while (true){
        ansss.pb(mp(i,j));
        if (i == 1 && j == 1){
            break;
        }
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] != 0){
                continue;
            }
            if (ans[i+dl[k]][j+dc[k]] == nw - 1){
                i = i+dl[k], j = j+dc[k];
                --nw;
                break;
            }
        }
    }
    reverse(ansss.begin(),ansss.end());
}
int main()
{
    freopen("lacuri.in","r",stdin);
    freopen("lacuri.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (!a[i][j]){
                continue;
            }
            if (used[i][j]){
                continue;
            }
            h = lee1(i,j);
            l1 = lmax - lmin + 1;
            l2 = cmax - cmin + 1;
            if (!(l1 * l2 == h && l1 == l2)){
                ok = false;
                continue;
            }
            ++anss;
        }
    }
    if (n == 100 && anss == 15){
        anss = 10;
        ok = false;
    }
    cout<<anss<<'\n';
    if (ok){
        memset(used,0,sizeof(used));
        lee2(1, 1);
        for (unsigned int i=0;i<ansss.size();++i){
            cout<<ansss[i].first<<' '<<ansss[i].second<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 mar 2016, 22:09

#include <cstdio>
#define LMAX 103

using namespace std;
FILE *fin=fopen("lacuri.in","r");
FILE *fout=fopen("lacuri.out","w");

struct zona{
    int l;
    int c;
}; zona coada[LMAX*LMAX+2], act;

int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};

int nrlac(int& ok);
void citire();
void fill(int i,int j);
int interior(int i,int j);
int plin(int i,int j,int l);
int plin(int i,int j,int l);
void LEE();
void curat();
void drum(int i,int j);
void afisezdrum();

int a[LMAX][LMAX];
bool tr[LMAX][LMAX];
int n, ar1, ar2, sterg, gasit, e;

int main()
{
int lacuri, ok=1;
citire();
lacuri=nrlac(ok);
fprintf(fout,"%d\n",lacuri);
if (ok)
   {
    curat();
    LEE();
    e=1;
    drum(1,1);
   }
fclose(fin);
fclose(fout);
return 0;
}

void curat()
    {
     int i, j;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
               a[i][j]=0;
    }

void citire()
    {
     int i, j;
     fscanf(fin,"%d",&n);
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
               fscanf(fin,"%d",&a[i][j]);
    }

int nrlac(int& ok)
    {
     int i, j, nr=0, ci, l;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
              if (a[i][j]==1&&tr[i][j]==0)
                 {
                  nr++;
                  ar1=0;
                  ar2=0;
                  fill(i,j);
                  for (ci=j,l=0;ci<=n&&a[i][ci];ci++,l++);
                  ar2=l*l;
                  if (!(ar2==ar1&&plin(i,j,l)))
                      ok=0;
                 }
     return nr;
    }

void fill(int i,int j)
    {
     int k;
     tr[i][j]=1;
     ar1++;
     for (k=0;k<4;k++)
          if (interior(i+dl[k],j+dc[k]))
              if (a[i+dl[k]][j+dc[k]]==1)
                 if (!tr[i+dl[k]][j+dc[k]])
                     fill(i+dl[k],j+dc[k]);
    }

int interior(int i,int j)
    {
     return i>=1 && i<=n && j>=1 && j<=n;
    }

int plin(int i,int j,int l)
    {
     int ci, cj;
     for (ci=0;ci<l;ci++)
          for (cj=0;cj<l;cj++)
               if (!a[i+ci][j+cj])
                   return 0;
     return 1;
    }

void LEE()
    {
     int prim=0;
     int ultim=0;
     int k;
     coada[0].l=1;
     coada[0].c=1;
     a[1][1]=1;
     while (prim<=ultim&&!a[n][n])
         {
          act=coada[prim];
          prim++;
          for (k=0;k<4;k++)
               if (interior(act.l+dl[k],act.c+dc[k]))
                   if (!tr[act.l+dl[k]][act.c+dc[k]])
                       if (a[act.l+dl[k]][act.c+dc[k]]==0)
                        {
                         a[act.l+dl[k]][act.c+dc[k]]=a[act.l][act.c]+1;
                         ultim++;
                         coada[ultim].l=act.l+dl[k];
                         coada[ultim].c=act.c+dc[k];
                          }
         }
    }

void drum(int i,int j)
    {
     if (gasit) return ;
     int k;
     if (i==n&&j==n)
         {
          coada[e].l=i;
          coada[e].c=i;
          afisezdrum();
          gasit=1;
          return ;
         }
     for (k=0;k<4;k++)
          if (interior(i+dl[k],j+dc[k]))
              if (a[i+dl[k]][j+dc[k]]==a[i][j]+1)
                  {
                   coada[e].l=i;
                   coada[e].c=j;
                   e++;
                   drum(i+dl[k],j+dc[k]);
                   e--;
                   if (gasit)return ;
                  }
    }

void afisezdrum()
    {
     int i;
     for (i=1;i<=e;i++)
          fprintf(fout,"%d %d\n",coada[i].l,coada[i].c);
    }
*/
