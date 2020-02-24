#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 205
using namespace std;
char s[nmax][nmax];
int x1, y11, x2, y2;
int n, m, ans;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool uz[nmax][nmax];
queue< pair <int , pii > > q;
pair< int, pii > act;
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}
int getAns(int l, int c, int le, int ce){
    memset(uz,0,sizeof(uz));
    while (!q.empty()){
        q.pop();
    }
    q.push(make_pair(1,make_pair(l,c)));
    uz[l][c] = true;
    int i, j;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.second.first;
        j = act.second.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (s[i+dl[k]][j+dc[k]] == 'b'){
                continue;
            }
            if (uz[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (i+dl[k] == le && j+dc[k] == ce){
                return act.first + 1;
            }
            uz[i+dl[k]][j+dc[k]]=true;
            q.push(make_pair(act.first+1,make_pair(i+dl[k],j+dc[k])));
        }
    }
    return -1;
}
int main()
{
    freopen("abq.in","r",stdin);
    freopen("abq.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%s",s[i]+1);
    }
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;++i){
        scanf("%d %d %d %d",&x1,&y11,&x2,&y2);
        if (!(s[x1][y11] == 'a' && s[x2][y2] == 'a')){
            printf("-1\n");
            continue;
        }
        printf("%d\n",getAns(x1,y11,x2,y2));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
14 ian 2017, 23:01
90 puncte

#include <fstream>
#define LMAX 205

using namespace std;
ifstream fin("abq.in");
ofstream fout("abq.out");

struct element{
    int x;
    int y;
};
element c[LMAX*LMAX];

int a[LMAX][LMAX];
int n, m;

int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void citire();
void bordare();
void rezolvari();
void restabilire(int nr);

int LEE(int xs, int ys, int xf, int yf);

int main()
{
citire();
bordare();
rezolvari();
fin.close();
fout.close();
return 0;
}

void citire()
    {
     int i, j;
     char c;
     fin>>n>>m;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
              {
               fin>>c;
               if (c=='a')
                   a[i][j]=0;
                   else
                   a[i][j]=-1;
              }
    }

void rezolvari()
    {
     int nr;
     int i;
     fin>>nr;
     int xs, ys;
     int xf, yf;
     for (i=1;i<=nr;i++)
        {
         fin>>xs>>ys>>xf>>yf;
         if (a[xs][ys]==-1)
             fout<<-1<<'\n';
             else
             fout<<LEE(xs,ys,xf,yf)<<'\n';
        }
    }

void restabilire(int nr)
    {
     int i;
     for (i=1;i<=nr;i++)
          a[c[i].x][c[i].y]=0;
    }

int LEE(int xs, int ys, int xf, int yf)
    {
     int st, dr;
     int k;
     int val;
     st=dr=1;
     c[1].x=xs;
     c[1].y=ys;
     element element;
     a[xs][ys]=1;
     while (st<=dr && !a[xf][yf])
         {
          element=c[st];
          st++;
          for (k=0;k<4;k++)
              if (a[element.x+dl[k]][element.y+dc[k]]==0)
                 {
                  a[element.x+dl[k]][element.y+dc[k]]=a[element.x][element.y]+1;
                  dr++;
                  c[dr].x=element.x+dl[k];
                  c[dr].y=element.y+dc[k];
                  if (element.x+dl[k]==xf&&element.y+dc[k]==yf)
                     {
                      val=a[element.x+dl[k]][element.y+dc[k]];
                      restabilire(dr);
                      return val;
                     }
                  }
         }
     if (a[xf][yf]!=0)
        val=a[xf][yf];
        else
        val=-1;
     restabilire(dr);
     return val;
    }

void bordare()
    {
     int i;
     for(i=0; i<=m+1; i++)
        {
         a[0][i]=-1;
         a[n+1][i]=-1;
        }
     for(i=0; i<=n+1; i++)
        {
         a[i][0]=-1;
         a[i][m+1]=-1;
        }
    }
*/
