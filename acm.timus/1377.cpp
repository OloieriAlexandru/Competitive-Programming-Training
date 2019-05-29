#include <bits/stdc++.h>
#define nmax 105
using namespace std;
bool viz[nmax][nmax], first;
int nr, i, j, k, ans, n, m;
int i1, i2, j1, j2, cnt;
int dl[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
bool interior(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=m;
}
void moveNext()
{
    if ((!interior(i+dl[k],j+dc[k])) || viz[i+dl[k]][j+dc[k]])
        ++k, k = k % 4;
    i+=dl[k];
    j+=dc[k];
}
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%d %d",&i1,&j1);
    scanf("%d %d",&i2,&j2);
    nr = n * m;
    i = j = 1;
    while (true)
    {
        viz[i][j] = true;
        if (first)
        {
            ++ans;
            if ((i1 == i && j1 == j) || (i2 == i && j2 == j))
            {
                break;
            }
        }
        else
        {
            if ((i1 == i && j1 == j) || (i2 == i && j2 == j))
            {
                first = true;
            }
        }
        ++cnt;
        if (cnt == nr) break;
        moveNext();
    }
    printf("%d\n",ans);
    return 0;
}