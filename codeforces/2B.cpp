#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
struct cell
{
    int p2, p5;
};
cell a[nmax][nmax], v1, v2;
int n, x, m1, m2, ln, lin, col;
cell dp[nmax][nmax];
bool path[nmax][nmax], path2[nmax][nmax], ex;
char ans[nmax*10];
void reconstructPath(bool path[nmax][nmax])
{
    int l = n, c = n;
    while (l > 1 && c > 1)
    {
        if (path[l][c])
            ans[ln++] = 'D', --l;
        else
            ans[ln++] = 'R', --c;
    }
    while (l > 1)
        --l, ans[ln++] = 'D';
    while (c > 1)
        --c, ans[ln++] = 'R';
    reverse(ans, ans + ln);
    printf("%s\n", ans);
}
void build0Ans(int l, int c)
{
    printf("1\n");
    int i = 1, j = 1;
    while (i < l)
    {
        ++i;
        printf("D");
    }
    while (j < c)
    {
        ++j;
        printf("R");
    }
    while (l < n)
    {
        ++l;
        printf("D");
    }
    while (c < n)
    {
        ++c;
        printf("R");
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            scanf("%d",&x);
            while (x > 1 && x % 5 == 0)
                ++a[i][j].p5, x /= 5;
            while (x > 1 && x % 2 == 0)
                ++a[i][j].p2, x /= 2;
            if (x == 0)
            {
                ex = true;
                lin = i, col = j;
            }
        }
    for (int i=1; i<=n; ++i)
    {
        path[1][i] = 0;
        path2[1][i] = 0;
        dp[1][i].p2 = a[1][i].p2 + dp[1][i-1].p2;
        dp[1][i].p5 = a[1][i].p5 + dp[1][i-1].p5;
    }
    for (int i=1; i<=n; ++i)
    {
        path[i][1] = 1;
        path2[i][1] = 1;
        dp[i][1].p2 = a[i][1].p2 + dp[i-1][1].p2;
        dp[i][1].p5 = a[i][1].p5 + dp[i-1][1].p5;
    }
    for (int i=2; i<=n; ++i)
        for (int j=2; j<=n; ++j)
        {
            v1.p2 = a[i][j].p2 + dp[i-1][j].p2;
            v1.p5 = a[i][j].p5 + dp[i-1][j].p5;

            v2.p2 = a[i][j].p2 + dp[i][j-1].p2;
            v2.p5 = a[i][j].p5 + dp[i][j-1].p5;

            if (v1.p2 <= v2.p2)
                path[i][j] = 1, dp[i][j].p2 = v1.p2;
            else
                path[i][j] = 0, dp[i][j].p2 = v2.p2;

            if (v1.p5 <= v2.p5)
                path2[i][j] = 1, dp[i][j].p5 = v1.p5;
            else
                path2[i][j] = 0, dp[i][j].p5 = v2.p5;
        }
    if (dp[n][n].p2 <= dp[n][n].p5)
    {
        if (ex && dp[n][n].p2)
        {
            build0Ans(lin, col);
            return 0;
        }
        cout<<dp[n][n].p2<<'\n';
        reconstructPath(path);
    }
    else
    {
        if (ex && dp[n][n].p5)
        {
            build0Ans(lin, col);
            return 0;
        }
        cout<<dp[n][n].p5<<'\n';
        reconstructPath(path2);
    }
    return 0;
}
