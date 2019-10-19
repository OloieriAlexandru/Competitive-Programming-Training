#include <bits/stdc++.h>
#define nmax 305
using namespace std;
int a[nmax][nmax], n, curr;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        if (i % 2)
            for (int j=1; j<=n; ++j)
                a[j][i] = ++curr;
        else
            for (int j=n; j>=1; --j)
                a[j][i] = ++curr;
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
