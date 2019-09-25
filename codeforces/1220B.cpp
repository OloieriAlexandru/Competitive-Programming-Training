#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, a[nmax][nmax], d, ans[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    d = a[1][2] / sqrt(1LL * a[1][2] * a[2][3] / a[1][3]);
    cout<<d<<' ';
    for (int i=2;i<=n;++i)
        cout<<a[1][i]/d<<' ';
    cout<<'\n';
    return 0;
}
