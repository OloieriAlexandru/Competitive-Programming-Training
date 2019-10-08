#include <bits/stdc++.h>
#define nmax 10
using namespace std;
char a[nmax][nmax], ch;
int n=8, l, c;
bool ok;
int dl[]= {-1,1,2,2,1,-1,-2,-2};
int dc[]= {2,2,1,-1,-2,-2,-1,1};
int dl1[] = {-1,-1,1,1};
int dc1[] = {-1,1,1,-1};
int dl2[] = {-1,0,1,0};
int dc2[] = {0,1,0,-1};
int dl3[] = {-1,-1,0,1,1,1,0,-1};
int dc3[] = {0,1,1,1,0,-1,-1,-1};
bool interior(int i, int j)
{
    return i>=1&&i<=8&&j>=1&&j<=8;
}
bool wtc(int i, int j)
{
    return a[i][j] >= 'A' && a[i][j] <= 'Z';
}
bool im(int i, int j)
{
    return a[i][j] >= 'a' && a[i][j] <= 'z';
}
bool isOk(int i, int j)
{
    return i == l && j == c;
}
int main()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>a[i][j];
    cin>>ch>>l;
    l = 8 - l + 1;
    c = ch - 'a' + 1;
    for (int i=n; i>=1 && !ok; --i)
        for (int j=1; j<=n && !ok; ++j)
        {
            if (!(a[i][j]>='a' && a[i][j]<='z'))
                continue;
            if (a[i][j] == 'p')
            {
                if ((wtc(i-1,j-1) && isOk(i-1,j-1)) || (wtc(i-1,j+1) && isOk(i-1,j+1)))
                    ok = true;
                continue;
            }
            if (a[i][j] == 't' || a[i][j] == 'r')
            {
                for (int k=0; k<4 && !ok; ++k)
                {
                    int l = i+dl2[k];
                    int c = j+dc2[k];
                    while (interior(l, c))
                    {
                        if (im(l, c)) break;
                        if (a[l][c] == '.')
                        {
                            l += dl2[k];
                            c += dc2[k];
                            continue;
                        }
                        if (isOk(l, c))
                        {
                            ok = true;
                            break;
                        }
                        break;
                    }
                }
            }
            if (a[i][j] == 'b' || a[i][j] == 'r')
            {
                for (int k=0; k<4 && !ok; ++k)
                {
                    int l = i+dl1[k];
                    int c = j+dc1[k];
                    while (interior(l, c))
                    {
                        if (im(l, c)) break;
                        if (a[l][c] == '.')
                        {
                            l += dl1[k];
                            c += dc1[k];
                            continue;
                        }
                        if (isOk(l, c))
                        {
                            ok = true;
                            break;
                        }
                        break;
                    }
                }
            }
            if (a[i][j] == 'k')
            {
                for (int k=0; k<8 &&!ok; ++k)
                {
                    int l = i+dl3[k];
                    int c = j+dc3[k];
                    if (!interior(l, c)) continue;
                    if (a[l][c] == '.') continue;
                    if (im(l, c)) continue;
                    if (wtc(l,c) && isOk(l, c))
                    {
                        ok = true;
                        break;
                    }
                }
            }
            if (a[i][j] == 'c')
            {
                for (int k=0; k<8 &&!ok; ++k)
                {
                    int l = i+dl[k];
                    int c = j+dc[k];
                    if (!interior(l, c)) continue;
                    if (a[l][c] == '.') continue;
                    if (im(l, c)) continue;
                    if (wtc(l,c) && isOk(l, c))
                    {
                        ok = true;
                        break;
                    }
                }
            }
        }
    if (ok)
        cout<<"Sim\n";
    else
        cout<<"Nao\n";
    return 0;
}
