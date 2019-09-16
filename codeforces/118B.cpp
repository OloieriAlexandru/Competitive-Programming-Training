#include <bits/stdc++.h>
#define nmax 33
using namespace std;
int n, ans[nmax][nmax], nw, cnt;
int main()
{
    cin>>n;
    for (int i=0; i<2*(n+1)-1; ++i)
        for (int j=0; j<2*(n+1)-1; ++j)
            ans[i][j] = -1;
    for (int act = 0; act < n; ++act)
    {
        int l = n;
        int c = act;
        while (l>=0 && c <= n)
        {
            ans[l][c] = nw;
            ++c, --l;
        }
        l = n;
        c = act;
        while (l<2*(n+1)-1 && c <= n)
        {
            ans[l][c] = nw;
            ++c, ++l;
        }
        ++nw;
    }
    nw = 0;
    for (int act = 2*(n+1)-2;act>n;--act)
    {
        int l = n;
        int c = act;
        while (l>=0 &&c>=n)
        {
            ans[l][c] = nw;
            --c, --l;
        }
        l = n;
        c = act;
        while (l<2*(n+1)-1 && c>=n)
        {
            ans[l][c] = nw;
            --c, ++l;
        }
        ++nw;
    }
    ans[n][n] = n;
    for (int i=0; i<2*(n+1)-1; ++i)
    {
        cnt = 0;
        for (int j=0; j<2*(n+1)-1; ++j)
        {
            if (ans[i][j] == -1)
                cout<<' ';
            else
                cout<<ans[i][j];
            if (ans[i][j] == 0)
            {
                if (i == 0 || i == 2*(n+1)-2)
                    break;
                ++cnt;
                if (cnt == 2) break;
            }
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
