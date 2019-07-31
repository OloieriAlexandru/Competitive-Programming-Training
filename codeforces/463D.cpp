#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int x, p[6][nmax], n, k, ans, ln, maxx[nmax];
vector<int>g[nmax];
bool uz[nmax];
void dfs(int k)
{
    uz[k] = true;
    int bst = 0;
    for (auto x:g[k])
    {
        if (!uz[x])
            dfs(x);
        bst = max(bst, maxx[x]);
    }
    maxx[k] = 1;
    maxx[k] = max(maxx[k], bst + 1);
    ans = max(ans, maxx[k]);
}
int main()
{
    cin >> n >> k;
    for (int t=1;t<=k;++t)
    {
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            p[t][x] = i;
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
    {
        if (i == j) continue;
        // ma uit daca pozitia lui i este inainte de pozitia lui j
        int cnt = 0;
        for (int t=1;t<=k;++t)
            if (p[t][i] < p[t][j]) ++cnt;
        if (cnt == k)
            g[i].push_back(j);
    }
    for (int i=1;i<=n;++i)
    {
        if (uz[i]) continue;
        dfs(i);
    }
    cout<<ans<<'\n';
    return 0;
}
