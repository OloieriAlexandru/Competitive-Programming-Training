#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define LMAX 1011
#define MAX(a,b) a>b?a:b
#define NMAX 14000
#define lld long long int
using namespace std;

int n, k;
int a[LMAX];
char s[NMAX];
lld ramas;

/*void parsareSirIntrare()
{
    char c;
    cin.get(c);
    cin.getline(s,LMAX);
    char *p;
    int nr = 0;
    p = strtok(s, " ");
    while (p)
    {
        a[++nr] = atoi(p);
        p = strtok(NULL, " ");
    }
}*/

bool bun(lld cat)
{
    for (int i = 1; i<=k; i++)
    {
        if (a[i]>=cat)continue; //am deja destule
        if (ramas < (cat-a[i]))//nu i mai pot da bomboane
        {
            return 0;
        }
        ramas-=(cat-a[i]);//am completat cu (cat-a[i]) bomboane
    }
    if (ramas<0)
    {
        return 0;
    }
    return 1;
}

lld getAns()
{
    lld ans = 0;
    lld sigurK = a[k];
    for (int i = 1; i<=k; i++)
    {
        a[i]-=sigurK;
    }
    lld am = 0;
    for (int i = k+1; i<=n; i++)
    {
        am+=a[i];
    }
    lld st = 0, dr = am;
    while (st<=dr)
    {
        lld m= (st+dr)/2;
        ramas = am;
        if (bun(m))
        {
            ans = MAX(ans, m);
            st = m+1;
        }
        else
        {
            dr = m-1;
        }
    }
    return ans+sigurK;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i= 1; i<=t; i++)
    {
        scanf("%d %d",&n,&k);
        memset(a,0,sizeof(a));
        //parsareSirIntrare();
        for (int j = 1;j<=n;j++)
        {
            scanf("%d",&a[j]);
        }
        sort(a+1,a+n+1,[](int a, int b)
        {
            return a>b;
        });
        printf("Case %d: ", i);
        if (n==k)
        {
            cout<<a[n]<<'\n';
        }
        else
        {
            cout<<getAns()<<'\n';
        }
    }
    return 0;
}