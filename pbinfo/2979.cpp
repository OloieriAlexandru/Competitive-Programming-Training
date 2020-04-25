#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int difTime(int lh, int lm, int ls, int h, int m, int s){
    if (lh == h){
        if (lm == m){
            return s - ls;
        }
        return (60 - ls) + (m - (lm+1))*60 + s;
    }
    int res = (60 - ls);
    ++lm;
    if (lm == 60){
        lm = 0;
        ++lh;
    } else {
        res += (60 - lm) * 60;
        lm = 0;
        ++lh;
    }
    res += 3600*(h-lh);
    res += m*60;
    res += s;
    return res;
}
int main()
{
    freopen("cartele.in","r",stdin);
    freopen("cartele.out","w",stdout);
    int t, n, h, m, s;
    int ans = 0, ans1 = 0, ans2 = 0;
    int lb, lf, lh, lm, ls;
    char gen, act;
    cin>>t>>n;
    cin>>gen>>act>>h>>m>>s;
    if (act == 'i'){
        if (gen == 'b'){
            ++ans1;
        } else {
            ++ans2;
        }
    }
    lb = ans1, lf = ans2;
    lh = h, lm = m, ls = s;
    int tot = 0;
    bool ok = false;
    if (lb % 2){
        ok = true;
    }
    for (int i=2;i<=n;++i){
        cin>>gen>>act>>h>>m>>s;
        if (act == 'i'){
            if (gen == 'b'){
                ++ans1;
            } else {
                ++ans2;
            }
        } else {
            if (gen == 'b'){
                --ans1;
            } else {
                --ans2;
            }
        }
        if (t == 2){
            if (lb && lf && lb == lf){
                ans += difTime(lh, lm, ls, h, m, s);
            }
        } else if (t == 3){
            if (!ok){
                if (ans1 % 2){
                    ok = true;
                    tot = 0;
                }
            } else {
                if (ans1 % 2){
                    tot += difTime(lh, lm, ls, h, m, s);
                    ans = max(ans, tot);
                } else {
                    tot += difTime(lh, lm, ls, h, m, s);
                    ans = max(ans, tot);
                    ok = false;
                    tot = 0;
                }
            }
        }
        lh = h, lm = m, ls = s;
        lb = ans1, lf = ans2;
    }

    if (t == 1){
        cout<<ans1<<' '<<ans2<<'\n';
    } else if (t == 2){
        cout<<ans<<'\n';
    } else if (t == 3){
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
