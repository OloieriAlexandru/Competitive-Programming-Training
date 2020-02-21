#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 305
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int dl[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
int n;
bool nw[nmax][nmax], mat[nmax][nmax];
bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=n;
}
bool replacee(int i, int j){
    int res = 0;
    for (int k=0;k<8;++k){
        if (!interior(i+dl[k],j+dc[k])){
            continue;
        }
        if (mat[i+dl[k]][j+dc[k]] == 1){
            ++res;
        }
    }
    return res>=3;
}
int solve(){
    int res = 0;
    while (true){
        ++res;
        bool ok = false;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                if (mat[i][j]){
                    nw[i][j] = true;
                    continue;
                }
                if (replacee(i,j)){
                    nw[i][j] = true;
                    ok = true;
                }
            }
        }
        if (!ok){
            break;
        }
        memcpy(mat, nw, sizeof(mat));
    }
    return res - 1;
}
int main()
{
    freopen("fillmat.in","r",stdin);
    freopen("fillmat.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            char ch;
            cin>>ch;
            mat[i][j] = ch - '0';
        }
    }
    cout<<solve()<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
8 mar 2016, 15:08
60 puncte

#include <fstream>
#define LMAX 302

using namespace std;
ifstream fin("fillmat.in");
ofstream fout("fillmat.out");

void citire();
int ebun(int i,int j);
int interior(int i,int j);
int FILLlee(int prim,int ultim);

struct celula{
    int l;
    int c;
    int pas;
};celula coada[LMAX*LMAX+2], act;

int dl[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,1,-1,-1,0,1};

int a[LMAX][LMAX];
int n;
int ok;

int main()
{
int i, j, pas=0;
citire();
ok=1;
int prim=0, ultim=-1;
for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
        if (!a[i][j])
            if (ebun(i,j)>=3)
                {
                 ultim++;
                 coada[ultim].l=i;
                 coada[ultim].c=j;
                 coada[ultim].pas=1;
                 }
pas=FILLlee(prim,ultim);
if (ultim==-1) fout<<0;
    else
    fout<<pas;
fin.close();
fout.close();
return 0;
}

void citire()
    {
     int i, j;
     char c;
     fin>>n;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
               {fin>>c;
               a[i][j]=c-'0';}
    }

int ebun(int i,int j)
    {
     int k, nr=0;
     for (k=0;k<8;k++)
          if (interior(i+dl[k],j+dc[k]))
              if (a[i+dl[k]][j+dc[k]])
                  nr++;
     return nr;
    }

int interior(int i,int j)
    {
     return i>=1 && i<=n && j>=1 && j<=n;
    }

int FILLlee(int prim,int ultim)
    {
     int k;
     while (prim<=ultim)
           {act=coada[prim];
            if (!a[act.l][act.c])
                {a[act.l][act.c]=1;
                prim++;
                for (k=0;k<8;k++)
                     if (interior(act.l+dl[k],act.c+dc[k]))

                         if (!a[act.l+dl[k]][act.c+dc[k]])
                            if (ebun(act.l+dl[k],act.c+dc[k])>=3)
                                 {
                                  ultim++;
                                  coada[ultim].l=act.l+dl[k];
                                  coada[ultim].c=act.c+dc[k];
                                  coada[ultim].pas=act.pas+1;
                                 }
                }
                else prim++;
           }
     return coada[ultim].pas;
    }
*/
