#include <bits/stdc++.h>
#define nmax 105
using namespace std;
char a[nmax][nmax], ch;
int n, m, cnt, x1, x2, y1, y2;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>cnt;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                a[i][j] = '.';
        while(cnt--)
        {
            cin>>x1>>y1>>x2>>y2>>ch;
            for (int i=x1;i<=x2;++i)
                for (int j=y1;j<=y2;++j)
                    a[i][j] = ch;
        }
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
                cout<<a[i][j];
            cout<<'\n';
        }
    }
    return 0;
}
