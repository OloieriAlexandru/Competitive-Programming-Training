#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int divNum(int x){
    int d, res = 2;
    for (int d=2;d*d<x;++d){
        if (x % d == 0){
            res += 2;
        }
    }
    if (d * d == x){
        ++res;
    }
    return res;
}
bool good(int x){
    while (x){
        if (x % 10 == 0){
            return false;
        }
        x /= 10;
    }
    return true;
}
int main()
{
    freopen("forus.in","r",stdin);
    freopen("forus.out","w",stdout);
    int t, n, x;
    cin>>t>>n;
    if (t == 1){
        int ans = 0;
        for (int i=1;i<=n;++i){
            cin>>x;
            if (good(x)){
                ++ans;
            }
        }
        cout<<ans<<'\n';
    } else {
        for (int i=1;i<=n;++i){
            int mx, res;
            cin>>x;
            mx = divNum(x), res = x;
            vector<int>cif;
            while (x){
                cif.pb(x%10);
                x /= 10;
            }
            reverse(cif.begin(), cif.end());
            for (int i=1;i<cif.size();++i){
                if (cif[i] == 0){
                    continue;
                }
                int act = 0;
                for (int j=i;j<cif.size();++j){
                    act = act * 10 + cif[j];
                }
                for (int j=0;j<i;++j){
                    act = act * 10 + cif[j];
                }
                int nrdact = divNum(act);
                if (nrdact < mx){
                    mx = nrdact, res = act;
                } else if (nrdact == mx){
                    if (act < res){
                        res = act;
                    }
                }
            }
            cout<<res<<' ';
        }
        cout<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
