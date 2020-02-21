#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 105
#define dmax 705
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, a[nmax], ans1, sum;
int dp[nmax][dmax], pv[nmax][dmax];
bool ok;
int main()
{
    freopen("cds.in","r",stdin);
    freopen("cds.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i] > 700){
            cout<<"0 0\n";
            return 0;
        }
        sum += a[i];
    }
    if (sum > 1400){
        cout<<"0 0\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=700;++j){
            if (j-a[i]<0){
                continue;
            }
            for (int k=0;k<i;++k){
                if (dp[k][j-a[i]]){
                    dp[i][j] = 1;
                    pv[i][j] = k;
                    break;
                }
            }
        }
    }
    for (int i=700;i>=0;--i){
        for (int j=0;j<=n;++j){
            if (dp[j][i]){
                ans1 = i;
                ok = true;
                break;
            }
        }
        if (ok){
            break;
        }
    }
    int an1 = min(sum-ans1,ans1);
    int an2 = max(sum-ans1,ans1);
    if (an1 > 700 || an2 > 700){
        cout<<"0 0\n";
        return 0;
    }
    cout<<an1<<' '<<an2<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
