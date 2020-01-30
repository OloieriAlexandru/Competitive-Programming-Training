#include <bits/stdc++.h>
#define MOD 101411
using namespace std;
vector<unsigned short>v[MOD];
bool uniquee(int x){
    int mod1 = x % MOD;
    unsigned short mod2 = x % 65536;
    for (int i=0;i<v[mod1].size();++i){
        if (v[mod1][i] == mod2){
            return false;
        }
    }
    v[mod1].push_back(mod2);
    return true;
}
int x, n, k, lp, un;
unsigned long long sum1 = 0, sum2 = 0;
int main()
{
    scanf("%d %d",&n,&k);
    if (k == 2){
        int ans = 0;
        for (int i=1;i<=n;++i){
            scanf("%d",&x);
            ans ^= x;
        }
        printf("%d\n", ans);
        return 0;
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        sum1 += x;
        if (uniquee(x)){
            sum2 += x;
            ++un;
        }
    }
    un *= k;
    lp = un - n;
    sum2 *= k;
    sum2 -= sum1;
    cout<<sum2/lp<<'\n';
    return 0;
}
