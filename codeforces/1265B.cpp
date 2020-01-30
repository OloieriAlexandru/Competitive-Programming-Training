#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    int t, n, x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>p(n+1);
        for (int i=1;i<=n;++i){
            cin>>x;
            p[x] = i;
        }
        vector<bool>inSecv(n+2,false);
        string ans;
        int nrs = 0;
        for (int i=1;i<=n;++i){
            int pact = p[i];
            inSecv[pact] = true;
            if (!inSecv[pact-1] && !inSecv[pact+1]){
                ++nrs;
            }
            if (inSecv[pact-1] && inSecv[pact+1]){
                --nrs;
            }
            ans.pb(nrs == 1 ? '1' : '0');
        }
        cout<<ans<<'\n';
    }
    return 0;
}
