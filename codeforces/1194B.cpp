#include <bits/stdc++.h>
#define nmax 50005
#define inf 999999999
using namespace std;
int n, m, lin, col;
int l[nmax], c[nmax], ans;
char ch;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        vector<string>mat(n+1);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
        {
            cin>>ch;
            mat[i].push_back(ch);
            if (ch == '*')
                ++l[i], ++c[j];
        }
        ans = n + m;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                ans = min(ans, (m-l[i]) + (n-c[j]) - (mat[i][j-1] == '.'));
        memset(l,0,sizeof(l));
        memset(c,0,sizeof(c));
        cout<<ans<<'\n';
    }
    return 0;
}
