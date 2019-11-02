#include <bits/stdc++.h>
#define nmax 10
#define inf 999999999
using namespace std;
int t, n = 9, fv[nmax];
int main()
{
    cin>>t;
    while(t--) {
        memset(fv, 0, sizeof(fv));
        for (int i=0; i<=9; ++i)
            cin>>fv[i];
        bool ok = true;
        for (int i=1;i<=9;++i)
            if (!fv[i]) {
                ok = false;
                cout<<i<<'\n';
                break;
            }
        if (!ok) {
            continue;
        }
        int fvMin = inf, pos;
        for (int i=1;i<=n;++i){
            if (fv[i] < fvMin){
                fvMin = fv[i], pos = i;
            }
        }
        if (fv[0] < fvMin) pos = 0, fvMin = fv[0];
        if (pos==0){
            cout<<1;
            for (int i=1;i<=fvMin+1;++i){
                cout<<pos;
            }
        } else {
            for (int i=1;i<=fvMin+1;++i){
                cout<<pos;
            }
        }
        cout<<'\n';
    }
    return 0;
}
