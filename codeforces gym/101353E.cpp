#include <stdio.h>
#define LMAX 100005
#define stang AB[nod<<1]
#define drept AB[nod<<1|1]

using namespace std;

int n;
int a[LMAX];
int ap[LMAX];
int target;
int AB[4*LMAX];

void upd(int nod, int st, int dr)
{
    if (st == dr)
    {
        AB[nod]++;
        return;
    }
    int m = (st+dr)/2;
    if (target<=m)
    {
        upd(nod<<1, st, m);
    }
    else
    {
        upd(nod<<1|1,m+1, dr);
    }
    AB[nod] = stang+drept;
}

int query(int nod, int st, int dr)
{
    return AB[nod];
}

int cat;
long long int af;
bool este;

int main()
{
    int t;
    scanf("%d",&t);
    for (int q = 1;q<=t;q++)
    {
        af = 0;
        este = 0;
        scanf("%d",&n);
        for (int i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i = n;i>=1;i--)
        {
            ap[a[i]]++;
            if (ap[a[i]]>1)
            {
                este = 1;
            }
            target = a[i];
            upd(1, 1, n);
            cat = query(1, 1, n);
            af+=(cat-ap[a[i]]);
        }
        if (este)
        {
            af++;
        }
        printf("%lld\n", af);
        for (int i= 1;i<=n;i++)
        {
            ap[i] = 0;
        }
        for (int i = 1;i<4*LMAX;i++)
        {
            AB[i]=0;
        }
    }
    return 0;
}
