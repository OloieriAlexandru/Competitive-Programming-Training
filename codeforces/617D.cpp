#include <bits/stdc++.h>
using namespace std;
int x[4], y[4], ans, n=3;
int main()
{
    for (int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    if (x[1] == x[2] && x[2] == x[3]) ans = 1;
    else if (y[1] == y[2] && y[2] == y[3]) ans = 1;
    else
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                for (int k=1;k<=n;++k)
                {
                    if (i == j || j == k || i == k) continue;
                    if ((x[i] == x[k] || x[j] == x[k]) && min(y[i],y[j]) <= y[k] && y[k] <= max(y[i], y[j])) ans = 2;
                    if ((y[i] == y[k] || y[j] == y[k]) && min(x[i],x[j]) <= x[k] && x[k] <= max(x[i], x[j])) ans = 2;
                }
            }
        }
    }
    if (!ans) ans = 3;
    cout<<ans<<'\n';
    return 0;
}
