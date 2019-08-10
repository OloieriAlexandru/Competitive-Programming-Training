#include <bits/stdc++.h>
#define nmax 55
using namespace std;
int n, m;
char a[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool ok;
vector<int>g[nmax*nmax];
bool uz1[nmax*nmax], uz2[nmax*nmax];
void dfs(int k, int lst)
{
    if (ok) return;
    uz1[k] = true;
    uz2[k] = true;
    for (auto x:g[k])
    {
        if (uz2[x] && lst != x)
        {
            ok = true;
            return;
        }
        if (uz1[x]) continue;
        dfs(x, k);
    }
    uz2[k] = false;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>a[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            for (int k=0; k<4; ++k)
            {
                if (a[i+dl[k]][j+dc[k]] == a[i][j])
                {
                    int l = i+dl[k];
                    int c = j+dc[k];
                    int ind1 = (i-1) * m + j;
                    int ind2 = (l-1) * m + c;
                    g[ind1].push_back(ind2);
                }
            }
        }
    int nn = n * m;
    for (int i=1; i<=nn; ++i)
    {
        if (uz1[i]) continue;
        dfs(i, -1);
        if (ok) break;
    }
    if (ok) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
