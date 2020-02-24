#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
using namespace std;
int n, k, x, a[nmax], ans1, ans2;
int fr[nmax], res, sum;
int binarySearch(int lft, int rgh, int x){
    int mid;
    while (lft < rgh){
        mid = (lft+rgh)/2;
        if (a[mid] < x){
            rgh = mid;
        } else {
            lft = mid + 1;
        }
    }
    return lft;
}
int main()
{
    freopen("calcule.in","r",stdin);
    freopen("calcule.out","w",stdout);
    scanf("%d %d",&n,&k);
    fr[0] = 1;
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        res = binarySearch(1, ans1, x);
        if (res > ans1 || a[res] >= x){
            a[++ans1] = x;
        } else {
            a[res] = x;
        }
        sum += x;
        sum %= k;
        ans2 += fr[sum];
        ans2 %= 20011;
        ++fr[sum];
    }
    printf("%d\n%d\n",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
10 mar 2016, 09:21
0 puncte

#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#define LMAX 650000
#define NMAX 100006

using namespace std;
FILE *fin=fopen("calcule.in","r");
FILE *fout=fopen("calcule.out","w");


void citire();
void sumepartiale();
int cb(int a);
int numarsubsiruri();
int numarsume();

int n, k, nr, ok;
int a[LMAX], s[LMAX];
int sir[NMAX];

int main()
{
int nrmin, smax;
citire();
nrmin=numarsubsiruri();
fprintf(fout,"%d\n",nrmin);
sumepartiale();
smax=numarsume();
fprintf(fout,"%d\n",smax);
fclose(fin);
fclose(fout);
return 0;
}


void citire()
    {
     char s[LMAX], c, *p;
     int i, x;
     fscanf(fin,"%d %d",&n,&k);
     c=fgetc(fin);
     fgets(s,LMAX,fin);
     p=strtok(s," ");
     for (i=0;i<n;i++)
          {
           x=atoi(p);
           a[i]=x;
           p=strtok(NULL," ");
          }
    }

void sumepartiale()
    {
     int i;
     for (i=0;i<n;i++)
          s[i]=a[i]%k;
    }

int numarsubsiruri()
    {
     int i, poz ,nrr;
     for (i=0;i<n;i++)
          {
           poz=cb(a[i]);
           if (poz==-1)
              {
               sir[nr]=a[i];
               nr++;
               sort(sir,sir+nr);
               continue;
              }
           sir[poz]=a[i];
          }
     nrr=nr;
     return nrr;
    }

int cb(int a)
    {
     int st, dr, mijl, maxim, ok=0;
     for (st=-1,dr=nr-1;st<=dr;)
         {
          mijl=(st+dr)/2;
          if (sir[mijl]<a)
              {
               ok=1;
               maxim=mijl;
               st=mijl+1;
              }
              else
              dr=mijl-1;
         }
     if (!ok)
         return -1;
         else
         return maxim;
    }

int numarsume()
    {
     int nr=0, i, sa, j;
     for (i=0;i<n;i++)
         {
          sa=0;
          for (j=i;j<n;j++)
              {
               sa=sa+s[j];
               if (sa%k==0)
                   nr++;
               sa=sa%k;
              }
         }
     return nr;
    }
*/
