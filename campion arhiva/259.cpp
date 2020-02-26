#include <cstdio>
#include <iostream>
#pragma GCC optimize ("O3")
#define nmax 155
using namespace std;
int n, m, x, a[nmax][nmax], maxx;
int main()
{
    freopen("livada.in","r",stdin);
    freopen("livada.out","w",stdout);
    scanf("%d %d %d",&n,&m,&x);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j;
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            if (a[i][j] > maxx){
                maxx = a[i][j];
            }
        }
    }
    if (x == 1){
        printf("%d\n",maxx);
        return 0;
    }
    int st = 1, dr = maxx, mi, ans = maxx, req, add, v;
    while (st <= dr){
        mi = (st+dr)/2;

        req = 0;
        for (i=1;i<=n;++i){
            for (j=1;j<=m;++j){
                if (a[i][j] <= mi){
                    continue;
                }
                for (add=0;;++add){
                    v = mi - add;
                    if (add*x+v>=a[i][j]){
                        break;
                    }
                }
                req += add;
            }
        }

        if (req <= mi){
            dr = mi-1;
            ans = mi;
        } else {
            st = mi+1;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
