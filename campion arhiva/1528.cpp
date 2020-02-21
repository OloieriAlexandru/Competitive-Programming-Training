#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 5005
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
lld ans, sum;
int n, ans1, ans2, ans3, a[nmax], sum1, sum2, sum3, sum4, s1, s2;
int minn, maxx;
int lrMin[nmax], lrMax[nmax], rlMin[nmax], rlMax[nmax];
int main()
{
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    lrMin[1] = lrMax[1] = a[1];
    rlMin[n] = rlMax[n] = a[n];
    for (int i=2;i<=n;++i){
        lrMin[i] = min(a[i],lrMin[i-1]);
        lrMax[i] = max(a[i],lrMax[i-1]);
    }
    for (int i=n-1;i>=1;--i){
        rlMin[i] = min(rlMin[i+1],a[i]);
        rlMax[i] = max(rlMax[i+1],a[i]);
    }
    for (int j=4;j<=n-4;++j){
        int i, k;
        sum1 = sum2 = sum3 = sum4 = -1;

        minn = a[j];
        maxx = a[j];
        for (int ii=j-1;ii>2;--ii){
            minn = min(minn,a[ii]);
            maxx = max(maxx,a[ii]);

            s1 = lrMax[ii-1]-lrMin[ii-1];
            s2 = maxx-minn;
            if (s1 + s2 >= sum1+sum2){
                sum1 = s1;
                sum2 = s2;
                i = ii-1;
            }
        }

        minn = a[j+1];
        maxx = a[j+1];
        for (int ii=j+2;ii<=n-2;++ii){
            minn = min(minn,a[ii]);
            maxx = max(maxx,a[ii]);

            s1 = maxx-minn;
            s2 = rlMax[ii+1]-rlMin[ii+1];
            if (s1 + s2 > sum3 + sum4){
                sum3 = s1;
                sum4 = s2;
                k = ii;
            }
        }

        sum = sum1+sum2+sum3+sum4;
        if (sum > ans){
            ans = sum;
            ans1 = i, ans2 = j, ans3 = k;
        }
    }
    printf("%lld\n",ans);
    printf("%d %d %d\n",ans1,ans2,ans3);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
