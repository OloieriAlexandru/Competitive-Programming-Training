#include <bits/stdc++.h>
#define nmax 7
#define inf 999999999
using namespace std;
int n = 5, a[nmax][nmax], ans = inf, i[nmax], af[nmax];
bool distinct()
{
    for (int k=1; k<=5; ++k)
        for (int j=k+1; j<=5; ++j)
            if (i[k] == i[j]) return false;
    return true;
}
int main()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>a[i][j];
    for (i[1] = 1; i[1] <=5; ++i[1])
        for (i[2] = 1; i[2] <=5; ++i[2])
            for (i[3] = 1; i[3] <=5; ++i[3])
                for (i[4] = 1; i[4] <=5; ++i[4])
                    for (i[5] = 1; i[5] <=5; ++i[5])
                    {
                        if (!distinct() || i[4] == 3 || i[1] != 1 || i[5] != 5) continue;
                        int act = a[i[1]][i[2]] + a[i[2]][i[3]] + a[i[3]][i[4]] + a[i[4]][i[5]];
                        if (ans > act)
                        {
                            for (int k=1; k<=5; ++k)
                                af[k] = i[k];
                            ans = act;
                        }
                    }
    cout<<ans<<'\n';
    for (int k=1; k<=5; ++k)
        cout<<af[k]<<' ';
    cout<<'\n';
    return 0;
}
