#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 305
using namespace std;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
vector<int> g[nmax*nmax];
int n, ans[nmax*nmax], di[nmax*nmax], a[nmax][nmax], nm;
bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=n;
}
int ijToNode(int i, int j){
    return (i-1)*n+j;
}
int main()
{
    freopen("drumuri1.in","r",stdin);
    freopen("drumuri1.out","w",stdout);

    scanf("%d",&n);
    nm = n*n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            int thisNode, otherNode;
            thisNode = ijToNode(i,j);
            for (int k=0;k<4;++k){
                if (!interior(i+dl[k],j+dc[k])){
                    continue;
                }
                otherNode = ijToNode(i+dl[k],j+dc[k]);
                if (a[i][j] < a[i+dl[k]][j+dc[k]]){
                    ++di[otherNode];
                    g[thisNode].push_back(otherNode);
                }
            }
        }
    }
    queue<int>q;
    for (int i=1;i<=nm;++i){
        if (!di[i]){
            ans[i] = 1;
            q.push(i);
        }
    }
    int act;
    while (!q.empty()){
        act = q.front(); q.pop();
        for (int i=0;i<g[act].size();++i){
            --di[g[act][i]];
            ans[g[act][i]] += ans[act];
            if (!di[g[act][i]]){
                q.push(g[act][i]);
            }
        }
    }
    long long af = 0;
    for (int i=1;i<=nm;++i){
        if (!g[i].size()){
            af += ans[i];
        }
    }
    cout<<af<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
11 feb 2017, 22:18
0 puncte

#include <fstream>
#define LMAX 400

using namespace std;
ifstream fin("drumuri1.in");
ofstream fout("drumuri1.out");

int a[LMAX][LMAX];
bool viz[LMAX];
int m[LMAX][10];
int n;
int nrs;

int dl[]={-1, 0 , 1, 0};
int dc[]={0, 1, 0, -1};

void citire();
void construire_graf();
void calculare();
void afisare();
void DFS(int ord, int k);

int main()
{
citire();
construire_graf();
calculare();
afisare();
fin.close();
fout.close();
return 0;
}

void calculare()
    {
     int i;
     for (i=1;i<=n;i++)
          if (!m[i][0])continue;
              else
              if (!viz[i])
              {
               DFS(1, i);
              }
    }

void DFS(int ord, int k)
    {
     int i;
     viz[k]=1;
     for (i=1;i<=m[k][0];i++)
             {
              if (ord==1)
                  nrs++;
              DFS(ord+1, m[k][i]);
             }
    }

void afisare()
    {
     fout<<nrs<<'\n';
    }

void citire()
    {
     int i, j;
     fin>>n;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
               fin>>a[i][j];
    }

void construire_graf()
    {
     int i, j;
     int k;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
              {
               for (k=0;k<4;k++)
                    if (a[i+dl[k]][j+dc[k]]!=0&&a[i+dl[k]][j+dc[k]]>a[i][j])
                        m[a[i][j]][0]++, m[a[i][j]][m[a[i][j]][0]]=a[i+dl[k]][j+dc[k]];
              }
    }
*/
