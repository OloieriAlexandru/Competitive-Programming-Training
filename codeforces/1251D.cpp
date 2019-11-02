#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int t, n, median;
lld s;
pii a[nmax];
bool cmp(const pii&a, const pii&b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
bool ok(int m)
{
    lld spent = 0;
    int cnt = 0;
    vector<int>v;
    for (int i=1;i<=n;++i)
    {
        if (a[i].second < m)
            spent += a[i].first;
        else
        if (a[i].first >= m)
            spent += a[i].first, ++cnt;
        else
            v.push_back(a[i].first);
    }
    int more = max(0, (n+1)/2-cnt);
    if (more > v.size()) return false;
    for (int i=0;i<v.size();++i)
    {
        if (i >= v.size()-more) spent += m;
        else spent += v[i];
    }
    return spent <= s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld",&n,&s);
        lld dr = -1;
        for (int i=1;i<=n;++i){
            scanf("%d %d",&a[i].first,&a[i].second);
            dr = max(dr, (lld)a[i].second);
        }
        sort(a+1,a+n+1,cmp);
        int median = n / 2 + 1;
        lld ans = a[median].first;
        lld st = 1;
        while(st <= dr){
            lld mid = (st + dr) / 2;
            if (ok(mid)){
                ans = max(ans, mid);
                st = mid + 1;
            } else dr = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
