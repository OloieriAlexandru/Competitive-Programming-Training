#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int a[nmax], n, sum;
long double req = 4.5, act;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a+1,a+n+1);
    act = sum / (long double)n;
    if (act >= req)
    {
        cout<<"0\n";
        return 0;
    }
    for (int i=1; i<=n; ++i)
    {
        sum -= a[i];
        sum += 5;
        act = sum / (long double)n;
        if (act >= req)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    return 0;
}
