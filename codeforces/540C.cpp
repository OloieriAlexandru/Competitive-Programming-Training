#include <bits/stdc++.h>
#define nmax 505
using namespace std;
int a[nmax][nmax], n, m, k, old[nmax][nmax];
bool viz[nmax][nmax];
int xs, xf, ys, yf;
char ch;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior (int l, int c)
{
    return l>=1&&l<=n&&c>=1&&c<=m;
}
bool hasIntactNeightbor(int l, int c)
{
    for (int k=0; k<4; ++k)
        if (interior(l+dl[k],c+dc[k]))
            if (a[l+dl[k]][c+dc[k]] == 0)
                return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>ch;
            if (ch == 'X')
                a[i][j] = 1;
            else
                a[i][j] = 0;
            old[i][j] = a[i][j];
        }
    cin>>xs>>ys;
    cin>>xf>>yf;
    if (ys == yf && xf == xs)
    {
        if (hasIntactNeightbor(xs, ys))
            cout<<"YES\n";
        else
            cout<<"NO\n";
        return 0;
    }
    queue<pair<int,int>>q;
    q.push(make_pair(xs,ys));
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        for (int k=0; k<4; ++k)
        {
            if (!interior(act.first+dl[k],act.second+dc[k])) continue;
            if (a[act.first+dl[k]][act.second+dc[k]] && !(act.first+dl[k] == xf && act.second+dc[k] == yf)) continue;
            if (viz[act.first+dl[k]][act.second+dc[k]]) continue;
            viz[act.first+dl[k]][act.second+dc[k]] = true;
            if (!(act.first+dl[k] == xf && act.second+dc[k] == yf))
                a[act.first+dl[k]][act.second+dc[k]] = 1;
            q.push(make_pair(act.first+dl[k],act.second+dc[k]));
            if (viz[xf][yf]) break;
        }
        if (viz[xf][yf]) break;
    }
    if (!viz[xf][yf])
    {
        cout<<"NO\n";
        return 0;
    }
    int cnt = 0;
    for (int k=0;k<4;++k)
        if (interior(xf+dl[k],yf+dc[k]))
    {
        int l = xf+dl[k];
        int c = yf+dc[k];
        if (viz[l][c] && a[l][c] && !old[l][c])
            if (!cnt) cnt = 1;
            else a[l][c] = 0;
    }
    if ((!a[xf][yf] && hasIntactNeightbor(xf,yf)) || a[xf][yf])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
