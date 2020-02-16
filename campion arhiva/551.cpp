#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 65456
#define mod 12343
using namespace std;
int n, fv[nmax], diff, x, rep, maxx, ans;
int expLog(int v, int n){
    if (!n){
        return 1;
    }
    if (n&1){
        return (v*expLog((v*v)%mod,n>>1))%mod;
    }
    return expLog((v*v)%mod,n>>1);
}
int main()
{
    freopen("munte.in","r",stdin);
    freopen("munte.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        ++fv[x];
        if (fv[x] == 3){
            printf("0\n");
            return 0;
        }
        if (fv[x] == 2){
            ++rep;
        }
        if (fv[x] == 1){
            ++diff;
        }
        maxx = max(maxx, x);
    }
    if (fv[maxx] > 1){
        printf("0\n");
        return 0;
    }
    if (rep){
        printf("%d\n",expLog(2, (diff-rep-1)));
    } else {
        ans = expLog(2, diff-1);
        ans -= 2;
        if (ans < 0){
            ans = mod + ans;
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
