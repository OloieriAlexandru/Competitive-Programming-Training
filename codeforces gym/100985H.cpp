#include <bits/stdc++.h>
#define lld long long
#define nmax 100100
using namespace std;
int a[4][nmax], n;
lld d1, d2;
int main()
{
    cin>>n;
    for (int i=1;i<=3;++i)
    {
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    }
    for (int i=1;i<=n;++i)
    {
        d1 += 1LL*(a[2][i] - a[1][i])*(a[2][i] - a[1][i]);
        d2 += 1LL*(a[3][i] - a[1][i])*(a[3][i] - a[1][i]);
    }
    if (d1 <= d2)
        cout<<"Yan\n";
    else
        cout<<"MaratonIME\n";
    return 0;
}
