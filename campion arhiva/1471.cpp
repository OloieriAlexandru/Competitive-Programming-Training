#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
using namespace std;
vector<int>g[nmax], mx;
int n, m, x, y, ans[nmax], n1;
bool uz[nmax];
int main()
{
    freopen("grafxy.in","r",stdin);
    freopen("grafxy.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    scanf("%d",&n1);
    for (int i=1;i<=n1;++i){
        scanf("%d",&x);
        mx.pb(x);
    }
    scanf("%d",&n1);
    queue<int>q;
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        ans[x] = 0;
        uz[x] = true;
        q.push(x);
    }
    int act;
    while (!q.empty()){
        act = q.front();q.pop();
        for (int i=0;i<g[act].size();++i){
            if (uz[g[act][i]]){
                continue;
            }
            uz[g[act][i]] = true;
            ans[g[act][i]] = ans[act] + 1;
            q.push(g[act][i]);
        }
    }
    for (unsigned i=0;i<mx.size();++i){
        printf("%d\n",ans[mx[i]]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 feb 2017, 20:59
40 puncte

#include <cstdio>
#include <vector>
#include <queue>
#define LMAX 100002

using namespace std;
FILE *fin=fopen("grafxy.in","r");
FILE *fout=fopen("grafxy.out","w");

struct e{
vector<int> v;
};
e care[LMAX];

int n;
int nx, ny;
int ex[LMAX];
int ey[LMAX];
int viz[LMAX];

queue<int> C;

void citire();
void afisare();
void curat();
int BFS(int start);
bool ajy(int vf);

int main()
{
citire();
afisare();
fclose(fin);
fclose(fout);
}

void citire()
    {
     int i;
     int x, y;
     int m;
     fscanf(fin,"%d %d", &n, &m);
     for (i=1;i<=m;i++)
         {
          fscanf(fin,"%d %d", &x, &y);
          care[x].v.push_back(y);
          care[y].v.push_back(x);
         }
     fscanf(fin,"%d",&nx);
     for (i=1;i<=nx;i++)
         fscanf(fin,"%d", &ex[i]);
     fscanf(fin,"%d",&ny);
     for (i=1;i<=ny;i++)
         fscanf(fin,"%d", &ey[i]);
    }

void afisare()
    {
     int i;
     int dm;
     for (i=1;i<=nx;i++)
          {
           dm=BFS(ex[i]);
           fprintf(fout,"%d\n", dm);
          }
    }

int BFS(int start)
    {
     unsigned int i;
     int act;
     curat();
     viz[start]=1;
     C.push(start);
     while (!C.empty())
         {
          act=C.front();
          C.pop();
          for (i=0;i<care[act].v.size();i++)
               if (!viz[care[act].v[i]])
                  {
                   viz[care[act].v[i]]=viz[act]+1;
                   if (ajy(care[act].v[i]))
                       return viz[act];
                   C.push(care[act].v[i]);
                  }
         }
    }

void curat()
    {
     int i;
     for (i=1;i<=n;i++)
          viz[i]=0;
     while (!C.empty())
         C.pop();
    }

bool ajy(int vf)
    {
     int i;
     for (i=1;i<=ny;i++)
          if (ey[i]==vf)
              return 1;
     return 0;
    }
*/
