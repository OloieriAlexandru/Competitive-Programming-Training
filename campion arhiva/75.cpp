#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 100005
#define lld long long
using namespace std;
int n, a[nmax], maxx, ans, x;
bool ok(int m){
    lld req = 0;
    int more;
    for (int i=1;i<=n;++i){
        if (a[i] <= m){
            continue;
        }
        more = a[i] - m;
        req += (more + x - 2)/ (x-1);
    }
    return req <= m;
}
int main()
{
    freopen("uscat.in","r",stdin);
    freopen("uscat.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        maxx = max(maxx, a[i]);
    }
    scanf("%d",&x);
    if (x == 1){
        printf("%d\n",maxx);
        return 0;
    }
    int m, st = 1, dr = maxx;
    ans = maxx;
    while (st <= dr){
        m = (st+dr)/2;
        if (ok(m)){
            dr = m - 1;
            ans = m;
        } else {
            st = m + 1;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 feb 2017, 20:11
20 puncte
#include <cstdio>
#define LMAX 100005

using namespace std;
FILE *fin=fopen("uscat.in", "r");
FILE *fout=fopen("uscat.out", "w");

int n, x;
int a[LMAX];

void citire();
void afisare();

int calculare();

int main()
{
citire();
afisare();
fclose(fin);
fclose(fout);
return 0;
}

void citire()
    {
     int i;
     fscanf(fin,"%d", &n);
     for (i=1;i<=n;i++)
          fscanf(fin,"%d",&a[i]);
     fscanf(fin,"%d",&x);
    }

void afisare()
    {
     int rez=calculare();
     fprintf(fout,"%d\n",rez);
    }

int calculare()
    {
     int st=0, dr=a[n];
     int m;
     int t;
     int i;
     int ad;
     while (st+1<dr)
         {
          t=0;
          m=(st+dr)/2;
          for (i=1;i<=n;i++)
              if (a[i]>m)
              {
               ad=(a[i]-t)/x;
               if ((a[i]-t)%x!=0)
                   t++;
               t+=ad;
              }
          if (t<m)
              dr=m-1;
              else
              st=m+1;
         }
     return dr;
    }
*/
