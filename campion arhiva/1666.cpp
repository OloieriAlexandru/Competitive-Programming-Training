#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 86500
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
const int nm = 86400;
int n, mars[nmax], h, m, s, duration;
string intToTwoDigits(int v){
    string res;
    res.push_back(v/10+'0');
    res.push_back(v%10+'0');
    return res;
}
string convert(int s){
    string ans;
    int v1, v2, v3;
    v3 = s % 60;
    s -= v3;
    v2 = (s % 3600) / 60;
    s -= v2;
    v1 = s / 3600;
    ans += intToTwoDigits(v1);
    ans.push_back(':');
    ans += intToTwoDigits(v2);
    ans.push_back(':');
    ans += intToTwoDigits(v3);
    return ans;
}
int main()
{
    freopen("tv1.in","r",stdin);
    freopen("tv1.out","w",stdout);

    int t;
    scanf("%d",&t);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %d:%d:%d",&duration,&h,&m,&s);
        int tt = h * 60 * 60 + m * 60 + s;
        ++mars[tt];
        --mars[min(tt+duration,nm+1)];
    }
    int act = 0, ans = 0, ans2 = 0;
    for (int i=0;i<nm;++i){
        act += mars[i];
        if (t == 2){
            if (act > ans2){
                ans2 = act;
                ans = i;
            }
        } else {
            if (!act){
                ++ans;
            }
        }
    }
    cout<<convert(ans)<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
