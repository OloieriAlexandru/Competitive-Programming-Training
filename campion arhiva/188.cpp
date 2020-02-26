#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 55
using namespace std;
vector<int> jd[nmax];
int n, x, y, ans1, maxx;
bool cmp(int a, int b){
    return a > b;
}
int main()
{
    freopen("concurs.in","r",stdin);
    freopen("concurs.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %d",&x,&y);
        if (!jd[x].size()){
            ++ans1;
        }
        maxx = max(maxx, x);
        jd[x].pb(y);
    }
    printf("%d\n",ans1);
    for (int i=1;i<=maxx;++i){
        if (jd[i].size()){
            printf("%u ",jd[i].size());
            sort(jd[i].begin(),jd[i].end(),cmp);
        }
    }
    printf("\n");
    while (true){
        int maxx1 = 0, maxx2 = 0, poz1, poz2, cnt = 0;
        for (int i=1;i<=maxx;++i){
            if (!jd[i].size()){
                continue;
            }
            ++cnt;
            int vx = jd[i].size();
            if (vx>maxx1){
                maxx2=maxx1;
                poz2=poz1;
                maxx1=vx;
                poz1=i;
            } else if (vx > maxx2){
                maxx2 = vx;
                poz2 = i;
            }
        }
        if (!cnt){
            break;
        }
        if (cnt == 1){
            printf("%d %d\n",poz1, jd[poz1].back());
            break;
        } else {
            printf("%d %d\n",poz1, jd[poz1].back());
            jd[poz1].pop_back();
            printf("%d %d\n",poz2, jd[poz2].back());
            jd[poz2].pop_back();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 mar 2016, 13:45
93 puncte

#include <cstdio>
#include <algorithm>

using namespace std;
FILE *fin=fopen("concurs.in","r");
FILE *fout=fopen("concurs.out","w");

void citire();
int numar();
void numarelevijudete();
void sortez();
int maisunt();
void gasescmaxim(int& m1,int& m2,int& j1,int& j2);
void repartizez(int& m1,int& m2,int& j1,int& j2);

int criteriu(int a,int b)
    {
     return a>b;
    }

int a[52][502];
int n, nrj;

int main()
{
citire();
fprintf(fout,"%d\n",numar());
numarelevijudete();
sortez();
int m1, m2, j1, j2;
while (maisunt())
      {
       if (maisunt()==1)
           {
            gasescmaxim(m1,m2,j1,j2);
            fprintf(fout,"%d %d\n",j1,a[j1][a[j1][0]]);
            break;
           }
       gasescmaxim(m1,m2,j1,j2);
       repartizez(m1,m2,j1,j2);
      }
fclose(fin);
fclose(fout);
return 0;
}

void citire()
    {
     int i, j, e;
     fscanf(fin,"%d",&n);
     for (i=1;i<=n;i++)
         {
          fscanf(fin,"%d %d",&j,&e);
          a[j][0]++;
          a[j][a[j][0]]=e;
          if (j>nrj) nrj=j;
         }

    }

int numar()
    {
     int i, nr=0;
     for (i=1;i<=nrj;i++)
          if (a[i][0]>0)
              nr++;
     return nr;
    }

void numarelevijudete()
    {
     int i;
     for (i=1;i<=nrj;i++)
          if (a[i][0]>0)
              fprintf(fout,"%d ",a[i][0]);
     fprintf(fout,"\n");
    }

void sortez()
    {
     int i;
     for (i=1;i<=nrj;i++)
          if (a[i][0]>0)
             sort(a[i]+1,a[i]+a[i][0]+1,criteriu);
    }

int maisunt()
    {
     int i, nr=0;
     for (i=1;i<=nrj;i++)
          if (a[i][0]>0)
              nr++;
     return nr;
    }

void gasescmaxim(int& m1,int& m2,int& j1,int& j2)
    {
     int i;
     m1=0;j1=0;
     m2=0;j2=0;
     for (i=1;i<=nrj;i++)
          if (a[i][0]>m2)
              {if (a[i][0]>m1)
                  {if (m1>m2) {m2=m1;j2=j1;}
                   m1=a[i][0];j1=i;}
                  else
                  {m2=a[i][0];j2=i;}}
    }

void repartizez(int& m1,int& m2,int& j1,int& j2)
    {
     while (m2>0)
          {
           fprintf(fout,"%d %d\n",j1,a[j1][a[j1][0]]);
           fprintf(fout,"%d %d\n",j2,a[j2][a[j2][0]]);
           a[j1][0]--;
           a[j2][0]--;
           m2--;
           m1--;
          }
    }
*/
