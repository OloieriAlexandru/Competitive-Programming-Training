#include <bits/stdc++.h>
#define nmax 1000005
#define nmax2 105
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;
int shortp[nmax2][nmax2], n, m, p[nmax], lst;
vector<int>ans;
char ch;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            cin>>ch;
            if (ch == '1')
                shortp[i][j] = 1;
            else if (i != j)
                shortp[i][j] = inf;
        }
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (shortp[i][k] + shortp[k][j] < shortp[i][j])
                    shortp[i][j] = shortp[i][k] + shortp[k][j];
    cin>>m;
    for (int i=1; i<=m; ++i)
        cin>>p[i];
    ans.push_back(p[1]);
    for (int i=3; i<=m; ++i)
    {
        lst = ans.back();
        if (shortp[lst][p[i-1]]+shortp[p[i-1]][p[i]] > shortp[lst][p[i]])
            ans.push_back(p[i-1]);
    }
    ans.push_back(p[m]);
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}

/*#include <bits/stdc++.h>
#define nmax 1000005
#define nmax2 105
using namespace std;
int n, dp[nmax], lst[nmax], s[nmax], v1, v2, ln;
char ch;
bool mat[nmax2][nmax2];
vector<int>ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
    {
        cin>>ch;
        mat[i][j] = (ch == '1' ? true : false);
    }
    cin>>ln;
    for (int i=1;i<=ln;++i)
        cin>>s[i];
    dp[1] = 1;
    lst[2] = 1;
    dp[2] = 2;
    for (int i=3;i<=ln;++i)
    {
        dp[i] = dp[i-1] + 1;
        lst[i] = i-1;
        v2 = s[i];
        v1 = s[i-2];
        if (!mat[v1][v2] && v1 != v2)
        {
            if (dp[i] > dp[i-2] + 1)
            {
                dp[i] = dp[i-2]+1;
                lst[i] = i-2;
            }
        }
    }
    cout<<dp[ln]<<'\n';
    int act = ln;
    while (act)
    {
        ans.push_back(s[act]);
        act = lst[act];
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans)
        cout<<x<<' ';
    return 0;
}*/
