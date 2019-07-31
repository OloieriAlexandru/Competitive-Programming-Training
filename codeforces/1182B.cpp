#include <bits/stdc++.h>
#define nmax 505
using namespace std;
int n, m, total, ans = 0, curr = 1;
char ch;
bool mat[nmax][nmax], looking = true;
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>ch;
            if (ch == '*')
                mat[i][j] = 1, ++total;
        }
    for (int i=2; i<n && looking; ++i)
        for (int j=2; j<m && looking; ++j)
        {
            if (!mat[i][j]) continue;
            if (!mat[i-1][j]) continue;
            if (!mat[i+1][j]) continue;
            if (!mat[i][j-1]) continue;
            if (!mat[i][j+1]) continue;

            looking = false;
            int l = i-1, c = j-1;
            while (l >= 1)
            {
                if (!mat[l][j]) break;
                --l, ++curr;
            }
            l = i+1;
            while (l <= n)
            {
                if (!mat[l][j]) break;
                ++l, ++curr;
            }
            while (c >= 1)
            {
                if (!mat[i][c]) break;
                --c, ++curr;
            }
            c = j+1;
            while (c <= m)
            {
                if (!mat[i][c]) break;
                ++c, ++curr;
            }

            if (curr == total)
                ans = 1;
        }
    if (ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
