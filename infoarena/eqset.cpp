#include <bits/stdc++.h>
#define lld long long
#define nmax 33000
using namespace std;
vector<int>primes;
bool uz[nmax];
lld a, b, gc, cgc;
lld gcdd(lld a, lld b)
{
    lld c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
bool func(lld a, lld gc)
{
    if (a == 1) return true;
    if (gc == 1 && a != 1) return false;
    lld g = gcdd(a, gc);
    lld x = a / g;
    return func(x, g);
}
int main()
{
    freopen("eqset.in","r",stdin);
    freopen("eqset.out","w",stdout);
    int t;
    scanf("%d",&t);
    //ciur();
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        if (a == b)
        {
            printf("1\n");
            continue;
        }
        if (a == 1 || b == 1)
        {
            printf("0\n");
            continue;
        }
        gc = gcdd(a, b);
        bool ok = func(a, gc) && func(b, gc);
        if (!ok)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

