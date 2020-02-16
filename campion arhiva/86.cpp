#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax
#define inf
using namespace std;
int n, w, h, x1, x2, y, x, cnt, xmax = -1;
int main()
{
    freopen("lac.in","r",stdin);
    freopen("lac.out","w",stdout);
    scanf("%d %d",&w,&h);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %d %d",&y,&x1,&x2);
        if (x1 > x){
            if (xmax == -1 || x1 > xmax){
                printf("0\n");
                return 0;
            }
            x = xmax;
            ++cnt;
            xmax = x2;
            continue;
        }
        xmax = max(xmax, x2);
    }
    if (x == w){
        printf("%d\n",n-cnt+1);
    } else {
        if (xmax != w){
            printf("0\n");
        } else {
            ++cnt;
            printf("%d\n",n-cnt+1);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3 mar 2015, 13:33
50 puncte
#include <cstdio>

using namespace std;
FILE *fin=fopen("lac.in","r");
FILE *fout=fopen("lac.out","w");
int i,n,w,h,neimportant,ac,maxim,maximt,sch,af
;
struct obiect
{
    int in;
    int sf;
};obiect dim[100001];
int main()
{
fscanf(fin,"%d %d",&w,&h);
fscanf(fin,"%d",&n);
for (i=1;i<=n;i++)
     fscanf(fin,"%d %d %d",&neimportant,&dim[i].in,&dim[i].sf);
for (;ac<w;)
    {maxim=0;
     for (i=1;i<=n&&dim[i].in<=ac;i++)
          {if (dim[i].in<=ac)
              maxim=dim[i].sf;
           if (maxim>maximt)
               {maximt=maxim;}}
     ac=maximt;sch++;

    }
af=n-sch+1;
fprintf(fout,"%d",af);




fclose(fin);
fclose(fout);
return 0;
}
*/
