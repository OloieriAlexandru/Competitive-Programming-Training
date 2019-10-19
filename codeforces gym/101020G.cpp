#include <bits/stdc++.h>
#define nmax 22
using namespace std;
int n, m;
int dl[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char req[] = "ppie";
char a[nmax][nmax];
bool interior(int i, int j)
{
    return i>=1&&j>=1&&i<=n&&j<=m;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        bool ok = false;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                cin>>a[i][j];
        for (int i=1; i<=n&&!ok; ++i)
            for (int j=1; j<=m&&!ok; ++j)
            {
                for (int k=0; k<8; ++k)
                {
                    int tt = 0;
                    for (tt=1; tt<=3; ++tt)
                    {
                        if (!interior(i+(tt-1)*dl[k],j+(tt-1)*dc[k])) break;
                        if (a[i+(tt-1)*dl[k]][j+(tt-1)*dc[k]] != req[tt]) break;
                    }
                    if (tt == 4)
                    {
                        ok = true;
                        break;
                    }
                }
            }
        if (ok)
            cout<<"Cutie Pie!\n";
        else
            cout<<"Sorry Man\n";
    }
    return 0;
}
