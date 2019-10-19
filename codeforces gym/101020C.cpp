#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int a[nmax][nmax];
int main()
{
    int t, n, l1, l2, c, ans, act;
    cin>>t;
    while(t--)
    {
        ans = 0;
        memset(a,0,sizeof(a));
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>l1>>l2>>c;
            for (int j=0;j<c;++j)
                ++a[j][l1], --a[j][l2];
        }
        for (int i=0;i<100;++i)
        {
            // setez linia
            act = 0;
            for (int j=0;j<100;++j)
            {
                act += a[i][j];
                ans += (act ? 1 : 0);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
