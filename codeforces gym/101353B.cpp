#include <stdio.h>
#define NMAX 5005

using namespace std;

unsigned long long int p;
int r, n;

bool satisfies(int z)
{
    long double inm = ((long double)r)/(100.0);
    inm+=1.0;
    long double v = 1;
    while (z)
    {
        if (z&1)
        {
            v = v*inm;
            z--;
        }
        inm*=inm;
        z>>=1;
    }
    long double need = p;
    return v*n >= need;
}

int ans()
{
    int st = 1, dr = NMAX, minim = NMAX+1;
    while (st<=dr)
    {
        int m = (st+dr)/2;
        if (satisfies(m))
        {
            if (m<minim)
            {
                minim = m;
            }
            dr = m-1;
        }
        else
        {
            st = m+1;
        }
    }
    return minim;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int q = 1;q<=t;q++)
    {
        scanf("%d %d %lld",&n,&r,&p);
        if (n>=p)
        {
            printf("Case %d: 0\n", q);
            continue;
        }
        printf("Case %d: %d\n",q, ans());
    }
    return 0;
}
