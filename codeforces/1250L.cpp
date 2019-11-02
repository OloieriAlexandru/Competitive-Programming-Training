#include <bits/stdc++.h>
#define inf 999999999
using namespace std;
int a, b, c;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int ans = inf;
        // divide a in two classes
        for (int i=0;i<=a;++i){
            int v1 = i;
            int v2 = c;
            int v3 = a - i;
            int maxx = v1;
            maxx = max(maxx, v2);
            maxx = max(maxx, v3);
            int cb = b;
            cb -= (maxx - v1);
            cb -= (maxx - v2);
            cb -= (maxx - v3);
            if (cb <= 0){
                ans = min(ans, maxx);
                continue;
            }
            maxx += cb / 3 + (cb % 3 ? 1 : 0);
            ans = min(ans, maxx);
        }
        // divide c in two classes
        swap(a,c);
        for (int i=0;i<=a;++i){
            int v1 = i;
            int v2 = c;
            int v3 = a - i;
            int maxx = v1;
            maxx = max(maxx, v2);
            maxx = max(maxx, v3);
            int cb = b;
            cb -= (maxx - v1);
            cb -= (maxx - v2);
            cb -= (maxx - v3);
            if (cb <= 0){
                ans = min(ans, maxx);
                continue;
            }
            maxx += cb / 3 + (cb % 3 ? 1 : 0);
            ans = min(ans, maxx);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
