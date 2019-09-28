#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<string>a;
vector<vector<bool>>used;
vector<vector<int>>leem;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int xs, ys, xf, yf, n, m, d;
int isus, ijos, istanga, idreapta;
int jsus, jjos, jstanga, jdreapta;
bool interior(int l, int k)
{
    return l >= 0 && l < n && k >= 0 && k < m;
}
void lee(int l, int c)
{
    if (used[l][c]) return;
    queue<pair<int,int>>q;
    q.push(mp(l,c));
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        int i = x.first;
        int j = x.second;
        for (int k=0;k<4;++k)
        {
            if (interior(i+dl[k], j+dc[k]))
            {
                if (!used[i+dl[k]][j+dc[k]])
                {
                    used[i+dl[k]][j+dc[k]] = true;
                    leem[i+dl[k]][j+dc[k]] = leem[i][j]+1;
                    q.push(mp(i+dl[k], j+dc[k]));
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&d);
    a.resize(n);
    leem.resize(n);
    used.resize(n);
    for (int i=0; i<n; ++i)
    {
        used[i].resize(m, 0);
        leem[i].resize(m, 0);
    }
    for (int i=0; i<n; ++i)
        cin>>a[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            if (a[i][j] == 'S')
                xs = i, ys = j;
            if (a[i][j] == 'F')
                xf = i, yf = j;
        }
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (a[i][j] == 'M')
            {
                int dm = abs(xs-i) + abs(ys-j);
                if (dm <= d)
                {
                    cout<<"-1\n";
                    return 0;
                }

                istanga = i;
                idreapta = i;
                isus = i - d;
                ijos = i + d;

                jstanga = j - d;
                jdreapta = j + d;
                jsus = j;
                jjos = j;

                if (interior(istanga, jstanga))
                {
                    int l = istanga;
                    int c = jstanga;
                    while (interior(l, c) && c <= j)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        ++c, --l;
                    }
                    l = istanga;
                    c = jstanga;
                    used[l][c] = false;
                    while (interior(l, c) && c <= j)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        ++c, ++l;
                    }
                }
                if (interior(isus, jsus))
                {
                    int l = isus;
                    int c = jsus;
                    while (interior(l, c) && l <= i)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        --c, ++l;
                    }
                    l = isus;
                    c = jsus;
                    used[l][c] = false;
                    while (interior(l, c) && l <= i)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        ++c, ++l;
                    }
                }
                if (interior(ijos, jjos))
                {
                    int l = ijos;
                    int c = jjos;
                    while (interior(l, c) && l >= i)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        --c, --l;
                    }
                    l = ijos;
                    c = jjos;
                    used[l][c] = false;
                    while (interior(l, c) && l >= i)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        ++c, --l;
                    }
                }
                if (interior(idreapta, jdreapta))
                {
                    int l = idreapta;
                    int c = jdreapta;
                    while (interior(l, c) && c >= j)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        --l, --c;
                    }
                    l = idreapta;
                    c = jdreapta;
                    used[l][c] = false;
                    while (interior(l, c) && c >= j)
                    {
                        if (used[l][c]) break;
                        used[l][c] = true;
                        ++l, --c;
                    }
                }
            }
    lee(xs, ys);
    /*for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            cout<<leem[i][j]<<' ';
        cout<<'\n';
    }*/
    if (leem[xf][yf] == 0)
        cout<<"-1\n";
    else
        cout<<leem[xf][yf]<<'\n';
    return 0;
}
