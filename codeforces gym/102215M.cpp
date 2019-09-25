#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
using namespace std;
vector<pair<pii,int>>v;
lld t, n, x, y, nrv, rap, nrvact, rapact, gc;
vector<int>ans;
bool cmp(pair<pair<lld,lld>,int> a, pair<pair<lld,lld>,int> b)
{
    return a.first.second > b.first.second;
}
bool greaterr()
{
    lld t1 = 1LL * rapact * nrv;
    lld t2 = 1LL * rap * nrvact;
    return t1 > t2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        v.clear();
        ans.clear();
        nrv = rap = 0;
        for (int i=1;i<=n;++i)
        {
            scanf("%lld %lld",&x,&y);
            swap(x,y);
            nrv += x;
            rap += x*y;
            v.push_back(make_pair(make_pair(x,y),i));
        }
        sort(v.begin(), v.end(), cmp);
        for (int i=0;i<n;++i)
        {
            nrvact = nrv + 1;
            rapact = rap + v[i].first.second;
            if (greaterr())
            {
                nrv = nrvact;
                rap = rapact;
                ans.push_back(v[i].second);
            }
            else break;
        }
        gc = __gcd(nrv, rap);
        nrv /= gc;
        rap /= gc;
        printf("%lld/%lld\n", rap, nrv);
        printf("%d\n", ans.size());
        for (auto x:ans)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}
