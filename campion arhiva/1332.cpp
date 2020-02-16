#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 545
#define inf 999999999
using namespace std;
short int a[nmax][nmax];
int n, k, s[nmax][nmax], minn = inf, ans, nw;
short int x1, y111, x2, y2;
int main()
{
    short int i, j, t;
    freopen("radioactiv.in","r",stdin);
    freopen("radioactiv.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            scanf("%hu",&a[i][j]);
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    for (i=1;i<=n;++i){
        for (j=1;j<=n;++j){
            nw = a[i][j];
            for (t=1;t<k;++t){
                x1 = max(1, i-t); y111 = max(1, j-t);
                x2 = min(n, i+t); y2 = min(n, j+t);
                nw += (s[x2][y2] - s[x2][y111-1] - s[x1-1][y2] + s[x1-1][y111-1]);
            }
            if (nw < minn){
                minn = nw, ans = 1;
            } else if (nw == minn){
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
