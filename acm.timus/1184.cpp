#include <iostream>
#define MAX(a,b) a>b?a:b
#define LMAX 10005
#define lld long long int
using namespace std;

lld a[LMAX];
lld n, k;
char c;
lld maxim;

bool ok(lld l)
{
    lld countt = 0;
    for (int i = 1;i<=n;i++)
    {
        countt+= (a[i]/l);
    }
    return countt >= k;
}

int main()
{
    cin>>n>>k;
    for (int i = 1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c;
        cin>>c;
        a[i] = a[i] * 10 + (c-'0');
        cin>>c;
        a[i] = a[i] * 10 + (c-'0');
    }
    int st = 1, dr = 10000000;
    while (st<=dr)
    {
        int mid = (st+dr)/2;
        if (ok(mid))
        {
            st = mid+1;
            maxim = MAX(maxim, mid);
        }
        else
        {
            dr = mid-1;
        }
    }
    if (maxim<1)
    {
        cout<<"0.00\n";
    }
    else
    {
        cout<<maxim/100<<'.'<<(maxim/10%10?maxim/10%10:0)<<maxim%10<<'\n';
    }
    return 0;
}