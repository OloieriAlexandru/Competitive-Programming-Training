#include <bits/stdc++.h>
#define nmax 102
using namespace std;
int a[nmax][nmax], n, k, islands;
bool ok = false;
int main()
{
    cin>>n>>k;
    if (k == 0) ok = true;
    for (int i=1; i<=n && !ok; ++i)
    {
        int j;
        if (i % 2) j = 1;
        else j = 2;
        for (; j<=n && !ok; j+=2)
        {
            a[i][j] = 1;
            ++islands;
            if (islands == k)
            {
                ok = true;
                break;
            }
        }
    }
    if (ok)
    {
        cout<<"YES\n";
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=n; ++j)
                if (a[i][j] == 0) cout<<'S';
                else cout<<'L';
            cout<<'\n';
        }
    }
    else
        cout<<"NO\n";
    return 0;
}
