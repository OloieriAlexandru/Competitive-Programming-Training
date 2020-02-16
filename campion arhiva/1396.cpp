#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 105
using namespace std;
string a[nmax][nmax];
string start, finish;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int sc[nmax][nmax], n, m, ans[nmax][nmax];
bool used[nmax][nmax];
bool interior(int i, int j){
    return i>=1 && i<=n && j>=1 && j<=m;
}
bool good(int v1, int v2){
    for (int i=0;i<20;++i){
        if ((v1&(1<<i)) && !(v2&(1<<i))){
            return true;
        }
    }
    return false;
}
int lee(const string& st, const string& fi){
    int i, j;
    queue<pii>q;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j] == st){
                q.push(mp(i,j));
                used[i][j] = true;
                ans[i][j] = 1;
            }
        }
    }
    pii act;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        for (int k=0;k<4;++k){
            if (!interior(i+dl[k],j+dc[k])){
                continue;
            }
            if (!good(sc[i][j],sc[i+dl[k]][j+dc[k]])){
                continue;
            }
            if (used[i+dl[k]][j+dc[k]]){
                continue;
            }
            if (a[i+dl[k]][j+dc[k]] == fi){
                return ans[i][j] + 1;
            }
            used[i+dl[k]][j+dc[k]] = true;
            ans[i+dl[k]][j+dc[k]] = ans[i][j] + 1;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
    return 1;
}
int sumLetters(const string& s){
    int res = 0;
    for (unsigned i=0;i<s.size();++i){
        res += s[i];
    }
    return res;
}
int main()
{
    freopen("lgdrum.in","r",stdin);
    freopen("lgdrum.out","w",stdout);
    cin>>n>>m;
    cin>>start>>finish;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            sc[i][j] = sumLetters(a[i][j]);
        }
    }
    cout<<lee(start,finish);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>
#define LMAX 105
#define LMAX2 13

using namespace std;
ifstream fin("lgdrum.in");
ofstream fout("lgdrum.out");

struct casuta {
    int x;
    int y;
    int pas;
};
queue <casuta> Q;

int harta[LMAX][LMAX];
char h2[LMAX][LMAX][LMAX2];
int n, m;

int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};

char sa[LMAX2];
char sb[LMAX2];

int cod(char *s);
bool sepotriveste(int a, int b);
void LEE();

int main()
{
    casuta x;
    int pai;
    fin>>n>>m;
    fin>>sa>>sb;
    for (int i=1;i<=n;i++)
        {for (int j=1;j<=m;j++)
             {
              fin>>h2[i][j];
              pai=cod(h2[i][j]);
              //fout<<h2[i][j]<<pai<<' ';
              harta[i][j]=pai;
              if (!strcmp(h2[i][j],sa))
                {
                 x.x=i;
                 x.y=j;
                 x.pas=1;
                 Q.push(x);
                 //fout<<x.x<<' '<<x.y<<'\n';
                }
             }
        //fout<<'\n';
        }
    LEE();
    fin.close();
    fout.close();
    return 0;
}

void LEE()
{
    casuta act;
    casuta pus;
    int i, j;
    while (!Q.empty())
        {
         act=Q.front();
         Q.pop();
         i=act.x;
         j=act.y;
         for (int k=0;k<4;k++)
              if (i+dl[k]>=1&& i+dl[k]<=n&&j+dc[k]>=1&&j+dc[k]<=m)
              if (harta[i+dl[k]][j+dc[k]]>0&&sepotriveste(abs(harta[i+dl[k]][j+dc[k]]), abs(harta[i][j])))
                 {
                  pus.x=i+dl[k];
                  pus.y=j+dc[k];
                  pus.pas=act.pas+1;
                  harta[i+dl[k]][j+dc[k]]*=-1;
                  Q.push(pus);
                  if (!strcmp(sb,h2[pus.x][pus.y]))
                      goto aici;
                 }
        }
    aici:
    fout<<pus.pas<<'\n';
}

bool sepotriveste(int a, int b)
{
    int va, vb;
    for (int k=0;k<11;k++)
        {
         va=(1<<k)&a;
         vb=(1<<k)&b;
         if (va) va=1;
         if (vb) vb=1;
         if (va+vb==1&&vb==1) return 1;
        }
    return 0;
}

int cod(char *s)
{
    int ret=0;
    for (int i=0;*(s+i);i++)
         ret+=*(s+i);
    return ret;
}
*/
