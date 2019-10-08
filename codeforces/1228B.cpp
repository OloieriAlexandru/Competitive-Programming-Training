#include <bits/stdc++.h>
#define mod 1000000007
#define nmax 1005
using namespace std;
int n, m, x, cnt[nmax][nmax], pw, row[nmax], col[nmax];
int a[nmax][nmax];
void check()
{
    for (int i=1;i<=n;++i)
    {
        int cnt = 0;
        for (int j=1;j<=m;++j)
        {
            if (!a[i][j]) break;
            ++cnt;
        }
        if (cnt != row[i])
        {
            cout<<"0\n";
            exit(0);
        }
    }
    for (int j=1;j<=m;++j)
    {
        int cnt = 0;
        for (int i=1;i<=n;++i)
        {
            if (!a[i][j]) break;
            ++cnt;
        }
        if (cnt != col[j])
        {
            cout<<"0\n";
            exit(0);
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        cin>>row[i];
    for (int j=1; j<=m; ++j)
        cin>>col[j];
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=row[i];++j)
            a[i][j] = 1;
    }
    for (int j=1;j<=m;++j)
    {
        for (int i=1;i<=col[j];++i)
            a[i][j] = 1;
    }
    check();
    for (int i=1; i<=n; ++i)
    {
        x = row[i];
        for (int j=x+2; j<=m; ++j)
            if (i > col[j]+1)
                ++cnt[i][j];
    }
    for (int j=1; j<=m; ++j)
    {
        x = col[j];
        for (int i=x+2; i<=n; ++i)
            if (j > row[i]+1)
                ++cnt[i][j];
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (cnt[i][j] >= 2)
                ++pw;
    long long ans = 1;
    for (int i=1; i<=pw; ++i)
        ans = (ans * 2) % mod;
    cout<<ans<<'\n';
    return 0;
}
