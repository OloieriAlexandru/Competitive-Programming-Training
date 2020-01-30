#include <bits/stdc++.h>
#define inf 999999999999999LL
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a, b, c;
        cin>>a>>b>>c;
        long long ans = inf;
        int d[] = {-1,0,1};
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                for (int k=0;k<3;++k){
                    long long aa = a + d[i];
                    long long ab = b + d[j];
                    long long ac = c + d[k];
                    ans = min(ans, abs(aa-ab)+abs(aa-ac)+abs(ab-ac));
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
