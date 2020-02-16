#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 205
using namespace std;
char a[nmax][nmax];
int dl[] = {-1,0,1,0,-1,1,1,-1};
int dc[] = {0,1,0,-1,1,1,-1,-1};
int n, m, ans1, ans2, ans3, cnt1, cnt2;
bool used[nmax][nmax];
bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
void lee1(int l, int c){
    queue<pii>q;
    q.push(mp(l,c));
    used[l][c] = true;
    pii act;
    int i, j;
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
            if (a[i+dl[k]][j+dc[k]] != 'C'){
                continue;
            }
            used[i+dl[k]][j+dc[k]] = true;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int lee2(int l, int c){
    int res = 1;
    queue<pii>q;
    q.push(mp(l,c));
    used[l][c] = true;
    pii act;
    int i, j;
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
            if (a[i+dl[k]][j+dc[k]] != 'P'){
                continue;
            }
            ++res;
            used[i+dl[k]][j+dc[k]] = true;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
    return res;
}
int main()
{
    freopen("oras1.in","r",stdin);
    freopen("oras1.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j] == '.'){
                continue;
            }
            cnt2 = 0;
            for (int k=0;k<8;++k){
                if (!interior(i+dl[k],j+dc[k])){
                    continue;
                }
                if (a[i+dl[k]][j+dc[k]] != '.'){
                    ++cnt2;
                }
            }
            if (cnt2 < 8){
                ++ans1;
            }
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (used[i][j]){
                continue;
            }
            if (a[i][j] == 'C'){
                ++ans2;
                lee1(i, j);
            } else if (a[i][j] == 'P') {
                ans3 = max(ans3, lee2(i,j));
            }
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
26 nov 2016, 19:56
#include <fstream>
#define LMAX 205

using namespace std;
ifstream fin("oras1.in");
ofstream fout("oras1.out");

int n, m;
int a[LMAX][LMAX];
int nrc1;
int nrc2;
int nrc3;

int dl1[]={-1,0,1,0};
int dc1[]={0,1,0,-1};

int dl[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

void citire();
void afisare();
void c1();
void c2();
void c3();

void bkt1(int i, int j);
int bkt2(int i, int j);

bool interior(int i, int j);



int main()
{
citire();
c1();
c2();
c3();
afisare();
fin.close();
fout.close();
return 0;
}

void c3()
    {
     int i, j, act;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j]==1)
                   {
                    act=bkt2(i,j);
                    if (act>nrc3)
                        nrc3=act;
                   }
    }

int bkt2(int i, int j)
    {
     int k, r=0;
     a[i][j]*=-1;
     for (k=0;k<4;k++)
          if (interior(i+dl1[k],j+dc1[k]))
              if(a[i+dl1[k]][j+dc1[k]]==1)
                 r+=bkt2(i+dl1[k],j+dc1[k]);
     return 1+r;
    }

void afisare()
    {
     fout<<nrc1<<' '<<nrc2<<' '<<nrc3<<'\n';
    }

void c2()
    {
     int i, j;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j]==3)
                   {
                    nrc2++;
                    bkt1(i,j);
                   }
    }

void bkt1(int i, int j)
    {
     int k;
     a[i][j]*=-1;
     for (k=0;k<4;k++)
          if (interior(i+dl1[k],j+dc1[k]))
              if(a[i+dl1[k]][j+dc1[k]]==3)
                 bkt1(i+dl1[k],j+dc1[k]);
    }

bool interior(int i, int j)
    {
     return i>=1&&i<=n&&j>=1&&j<=m;
    }

int calc_vec(int i, int j)
    {
     int k;
     int nr=0;
     for (k=0;k<8;k++)
          if (interior(i+dl[k],j+dc[k]))
             if (a[i+dl[k]][j+dc[k]])
                nr++;
     return nr;
    }

void c1()
    {
     int i, j, nr;
     for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
               if (a[i][j])
                   {nr=calc_vec(i,j);
                    if (nr<8)
                        nrc1++;}
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
               if (c=='P')
                   a[i][j]=1;
                   else if (c=='S')
                            a[i][j]=2;
                            else if (c=='C')
                                     a[i][j]=3;
              }
    }
*/
