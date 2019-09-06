#include <bits/stdc++.h>
#define nmax 300
using namespace std;
int a[nmax][nmax], n, t, cnt;
bool interior(int i, int j)
{
    return i>=1&&i<=n&&j>=1&&j<=n;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>cnt;
        memset(a, 0, sizeof(a));
        n = 2 * cnt + 1;

        int up, down, l, r;
        up = down = l = r = n/2+1;
        int center = n / 2 + 1;
        while (true)
        {
            bool st = false;
            for (int i=center, j = l; j<=center; ++i, ++j)
            {
                if (interior(i, j))
                {
                    a[i][j] = 1;
                    st = true;
                }
            }
            if (!st) break;
            for (int i=center, j=r; j>=center; ++i,--j)
                if (interior(i, j))
                    a[i][j] = 1;
            for (int i=center, j=l; j<=center; --i, ++j)
                if (interior(i, j))
                    a[i][j] = 1;
            for (int i=center, j=r; j>=center; --i,--j)
                if (interior(i, j))
                    a[i][j] = 1;
            l -= 3;
            up -= 3;
            down += 3;
            r += 3;
        }
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                if (a[i][j]) cout<<'b';
                else cout<<'w';
            }
            cout<<'\n';
        }
    }
    return 0;
}
