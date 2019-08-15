#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int cnt[nmax*nmax], comps[nmax][nmax], a[nmax][nmax], n, m, nrc;
int ans[nmax][nmax];
char ch;
bool uz[nmax][nmax];
int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool interior(int l, int c)
{
    return l >= 1 && c >= 1 && l <= n && c <= m;
}
void bkt(int l, int c)
{
    ++cnt[nrc];
    uz[l][c] = true;
    comps[l][c] = nrc;
    for (int k=0; k<4; ++k)
    {
        if (interior(l+dl[k], c+dc[k]))
        {
            if (uz[l+dl[k]][c+dc[k]] || a[l+dl[k]][c+dc[k]] == 0)
                continue;
            bkt(l+dl[k], c+dc[k]);
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>ch;
            if (ch == '.')
                a[i][j] = 1;
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i][j] == 1 && !uz[i][j])
            {
                ++nrc;
                bkt(i, j);
            }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (a[i][j] == 1) continue;
            set<int>st;
            for (int k=0;k<4;++k)
                st.insert(comps[i+dl[k]][j+dc[k]]);
            for (auto x:st)
                ans[i][j] += cnt[x];
        }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            if (a[i][j] == 1)
                cout<<'.';
            else
                cout<<(ans[i][j] + 1)%10;
        }
        cout<<'\n';
    }
    return 0;
}
