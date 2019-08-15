#include <bits/stdc++.h>
using namespace std;
int n, k, a[101][101];
int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        for (int j=i; j<=n; ++j)
        {
            if (i == j)
            {
                if (k) a[i][j] = 1, --k;
            }
            else
            {
                if (k > 1) a[i][j] = a[j][i] = 1, k -= 2;
            }
        }
    if (k)
        cout<<"-1\n";
    else
    {
        for (int i=1; i<=n; ++i)
        {

            for (int j=1; j<=n; ++j)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
