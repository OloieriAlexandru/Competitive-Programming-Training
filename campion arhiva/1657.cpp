#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 300005
#define inf 999999999
using namespace std;
int t, n, lenMax, ans;
int a[nmax*2+2], b[nmax*2+2], *st, *dr;
string s;
int main()
{
    freopen("dominant.in","r",stdin);
    freopen("dominant.out","w",stdout);

    cin>>t;
    cin>>s;
    n = s.size();

    st = a + nmax;
    dr = b + nmax;

    for (int i=-n-1;i<=n+1;++i){
        st[i] = inf;
        dr[i] = -inf;
    }

    st[0] = dr[0] = 0;
    int sum = 0;
    for (int i=0;i<n;++i){
        if (s[i] == '1'){
            ++sum;
        } else {
            --sum;
        }
        st[sum] = min(st[sum],i+1);
        dr[sum] = max(dr[sum],i+1);
    }

    for (int i=-300000;i<300000;++i){
        if (st[i] == inf || dr[i+1] == -inf){
            continue;
        }
        lenMax = max(lenMax, dr[i+1] - st[i]);
    }

    if (t == 1){
        ans = lenMax;
    } else {
        int sum = 0;
        for (int i=0;i<lenMax;++i){
            if (s[i] == '1'){
                ++sum;
            } else {
                --sum;
            }
        }
        for (int i=lenMax;i<n;++i){
            if (sum > 0){
                ++ans;
            }
            if (s[i-lenMax] == '1'){
                --sum;
            } else {
                ++sum;
            }
            if (s[i] == '1'){
                ++sum;
            } else {
                --sum;
            }
        }
        if (sum > 0){
            ++ans;
        }
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
