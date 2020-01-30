#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
int n, type, a, b, cnt;
lld sum, add[nmax], el[nmax];
int main()
{
    cnt = 1;
    scanf("%d",&n);
    for (int tt=1;tt<=n;++tt){
        scanf("%d",&type);
        if (type == 1){
            scanf("%d %d",&a,&b);
            add[a] += b;
            sum += 1LL * a * b;
        }
        else if (type == 2){
            scanf("%d",&a);
            ++cnt;
            el[cnt]=a;
            sum+=a;
            add[cnt]=0;
        }
        else {
            sum-=add[cnt];
            sum-=el[cnt];
            add[cnt-1]+=add[cnt];
            --cnt;
        }
        double ans = (1.0 * sum)/cnt;
        cout<<setprecision(6)<<fixed<<ans<<'\n';
    }
    return 0;
}
