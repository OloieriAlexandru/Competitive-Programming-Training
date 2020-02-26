#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
#define inf 999999999
using namespace std;
int maxst[nmax], mindr[nmax], st[nmax], dr[nmax];
int maxSumSt[nmax], maxSumDr[nmax];
int ans = -inf, n, a[nmax];
int main()
{
    freopen("sir2dif.in","r",stdin);
    freopen("sir2dif.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        maxst[i] = max(a[i],maxst[i-1]);
    }
    mindr[n+1] = inf;
    for (int i=n;i>=1;--i){
        mindr[i] = min(a[i],mindr[i+1]);
    }
    maxSumSt[1] = -inf;
    for (int i=2;i<=n;++i){
        st[i] = maxst[i-1] - a[i];
        maxSumSt[i] = max(st[i],maxSumSt[i-1]);
    }
    maxSumDr[n] = -inf;
    for (int i=n-1;i>=1;--i){
        dr[i] = a[i] - mindr[i+1];
        maxSumDr[i] = max(dr[i],maxSumDr[i+1]);
    }
    for (int i=2;i<=n-2;++i){
        ans = max(ans, maxSumSt[i]+maxSumDr[i+1]);
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
11 apr 2017, 23:01
30 puncte

#include <cstdio>
#define NM 100002
#define INF -999999999
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

using namespace std;
FILE *fin=fopen("sir2dif.in","r");
FILE *fout=fopen("sir2dif.out","w");

int n;
int e[NM];
int maxst[NM];
int mindr[NM];
int st[NM];
int dr[NM];

int main()
{
int i;
int m=INF;
fscanf(fin,"%d",&n);
for (i=1;i<=n;i++)
    {
     fscanf(fin,"%d",&e[i]);
     maxst[i]=MAX(e[i],maxst[i-1]);
    }
mindr[n+1]=e[n]+1;
for (i=n;i>=1;i--)
     mindr[i]=MIN(e[i],mindr[i+1]);
for (i=2;i<=n;i++)
     st[i]=maxst[i-1]-e[i];
for (i=1;i<n;i++)
     dr[i]=e[i]-mindr[i+1];
for (i=2;i<=n-2;i++)
     m=MAX(m,st[i]+dr[i+1]);
fprintf(fout,"%d\n",m);
fclose(fin);
fclose(fout);
return 0;
}

#include <fstream>
#include <algorithm>
#define Nmax 100005
#define inFile "sir2dif.in"
#define outFile "sir2dif.out"

using namespace std;

int a[Nmax], n;
int st[Nmax], dr[Nmax];

int main()
{
    int i, minim, maxim, dif2max;

    // citire
    ifstream fin(inFile);
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> a[i];
    fin.close();

    // calcul st
    dr[n] = -10000000;
    minim = a[n];
    for (i = n - 1; i >= 1; --i)
    {
        dr[i] = max(a[i]-minim, dr[i+1]);
        minim = min(minim, a[i]);
    }

    // calcul dr
    st[1] = -10000000;
    maxim = a[1];
    for (i = 2; i <= n; ++i)
    {
        st[i] = max(maxim - a[i], st[i - 1]);
        maxim = max(maxim, a[i]);
    }

    // calcul dif2max
    dif2max = (a[1] - a[2]) + (a[3] - a[4]);
    for (i = 2; i <= n - 2; ++i)
        dif2max = max(dif2max, st[i] + dr[i+1]);

    //afisare
    ofstream fout(outFile);
    fout << dif2max << "\n";
    fout.close();

    return 0;
}


*/
