#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define nmax 77
using namespace std;
int n, m, xs, ys, xf, yf, ans[nmax][nmax];
bool visited[nmax][nmax];
char a[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j){
    return i>=0&&i<=(n+1)&&j>=0&&j<=(m+1);
}
void lee(int xs, int ys, int xf, int yf){
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
    queue<pii>q;
    pii act;
    int i, j;
    q.push(mp(xs,ys));
    visited[xs][ys] = true;
    while (!q.empty()){
        act = q.front();
        q.pop();
        i = act.first, j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])) {
                continue;
            }
            if (visited[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] == 'X' && !(i+dl[k] == xf && j+dc[k] == yf)){
                continue;
            }
            visited[i+dl[k]][j+dc[k]] = true;
            ans[i+dl[k]][j+dc[k]] = ans[i][j] + 1;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int main()
{
    freopen("inginer.in","r",stdin);
    freopen("inginer.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    while (true){
        cin>>xs>>ys>>xf>>yf;
        if (!xs){
            break;
        }
        lee(xs,ys,xf,yf);
        if (!visited[xf][yf]){
            cout<<"0\n";
        } else {
            cout<<ans[xf][yf]<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
13 oct 2015, 13:53
#include <fstream>

using namespace std;
ifstream fin("inginer.in");
ofstream fout("inginer.out");
int x1,x2,y3,y2,clin,ccol,vlin,vcol,prim,ultim,n,m,i,j,k,ok;
char c;
int circuit[78][78];
int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
struct circuit2
{
int lin,col;
};
circuit2 p[176*176];

int main()
{
fin>>n>>m;
fin.get(c);
for (i=1;i<=n;i++)
     {for (j=1;j<=m;j++)
          {fin.get(c);
          if (c=='X')
             circuit[i][j]=-1;
             else
             circuit[i][j]=0;}
     fin.get(c);
     }
ok=1;
while (1)
    {fin>>x1>>y3>>x2>>y2;
     if (x1==0 && x2==0 && y3==0 && y2==0)
         break;
     prim=ultim=0;
     p[0].lin=x1;
     p[0].col=y3;
     while (prim<=ultim && circuit[x2][y2]==-1)
          {clin=p[prim].lin;
           ccol=p[prim].col;
           prim++;
           for (k=0;k<=3;k++)
                {vlin=clin+dl[k];
                 vcol=ccol+dc[k];
                 if (circuit[vlin][vcol]==0&&vlin>=0&&vcol>=0&&vlin<=n+1&&vcol<=m+1||(circuit[vlin][vcol]==-1 && vlin==x2 && vcol==y2))
                    {circuit[vlin][vcol]=circuit[clin][ccol]+1;
                    ultim++;
                    p[ultim].lin=vlin;
                    p[ultim].col=vcol;

                    }
                }
          }
     if (circuit[x2][y2]==-1)
         fout<<0<<'\n';
         else
         fout<<circuit[x2][y2]+1<<'\n';
     for (i=0;i<=n+1;i++)
          for (j=0;j<=m+1;j++)
               {if (circuit[i][j]>0)
                    circuit[i][j]=0;}
     circuit[x2][y2]=-1;
     for (i=0;i<=176*176;i++)
          {p[i].lin=0;
          p[i].col=0;}

    }
fin.close();
fout.close();
return 0;
}
*/
