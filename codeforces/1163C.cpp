#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
using namespace std;
int n, x, y;
int x1, x2, y1, y2, act, a, b, c, gc;
lld ans;
vector<pii>v;
vector<pair<int,pii>>pts;
vector<pii>ck;
bool same(pair<int,pii> a, pair<int,pii> b)
{
    if (a.first != b.first) return false;
    if (a.second.first != b.second.first) return false;
    if (a.second.second != b.second.second) return false;
    return true;
}
bool same(pii a, pii b)
{
    return a.first == b.first && a.second == b.second;
}
int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x>>y;
        v.push_back(mp(x,y));
    }
    for (int i=0; i<v.size(); ++i)
        for (int j=i+1; j<v.size(); ++j)
        {
            x1 = v[i].first;
            y1 = v[i].second;
            x2 = v[j].first;
            y2 = v[j].second;
            a = y1-y2;
            b = x1-x2;
            gc = gcd(a,b);
            a /= gc;
            b /= gc;
            if (a < 0 || (a == 0 && b < 0))
                a *= -1, b *= -1;
            c = a * x1 - b * y1;
            pts.push_back(mp(a, mp(b,c)));
        }
    sort(pts.begin(), pts.end());
    //for (auto x:pts)
    //    cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<'\n';
    for (int i=0;i<pts.size();++i)
    {
        ck.push_back(mp(pts[i].first, pts[i].second.first));
        while (i < pts.size() && same(pts[i],pts[i+1]))
            ++i;
    }
    ans = (1LL * ck.size() * (ck.size()-1)) / 2;
    //cout<<'\n';
    for (int i=0;i<ck.size();++i)
    {
        act = 1;
        //cout<<ck[i].first<<' '<<ck[i].second<<'\n';
        while (i<ck.size() && same(ck[i], ck[i+1])) ++i, ++act;
        ans -= (1LL * act * (act-1))/2;
    }
    cout<<ans<<'\n';
    return 0;
}
