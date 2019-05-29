#include <bits/stdc++.h>
#define nmax 1000005
#define nmax2 30005
#define nmax3 200005
#define pii pair<int,pair<int,int>>
#define mp make_pair
using namespace std;
int n, m, a[nmax2];
int fv[nmax], dv;
int ans[nmax3];
vector<pii>q;
int l, r;
int ssqrt(int x)
{
    if (x<=1) return x;
    int d = 3;
    while (d*d<=x)++d;
    return d-1;
}
bool cmp(pii a, pii b)
{
    int v1 = a.second.first/dv;
    int v2 = b.second.first/dv;
    if (v1 == v2)
        return a.second.second < b.second.second;
    return v1 < v2;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0;i<m;++i)
    {
        scanf("%d %d",&l,&r);
        --l, --r;
        q.push_back(mp(i,mp(l,r)));
    }
    dv = ssqrt(m);
    sort(q.begin(), q.end(), cmp);
    int mo_left = 0, mo_right = -1, anss = 0;
    int lft, rgh;
    for (int i=0;i<m;++i)
    {
        lft = q[i].second.first;
        rgh = q[i].second.second;

        while (mo_right < rgh)
        {
            ++mo_right;
            ++fv[a[mo_right]];
            if (fv[a[mo_right]] == 1)
                ++anss;
        }
        while (mo_right > rgh)
        {
            --fv[a[mo_right]];
            if (!fv[a[mo_right]])
                --anss;
            --mo_right;
        }
        while (mo_left < lft)
        {
            --fv[a[mo_left]];
            if (!fv[a[mo_left]])
                --anss;
            ++mo_left;
        }
        while (mo_left > lft)
        {
            --mo_left;
            ++fv[a[mo_left]];
            if (fv[a[mo_left]]==1)
                ++anss;
        }
        ans[q[i].first] = anss;
    }
    for (int i=0;i<m;++i)
        printf("%d\n",ans[i]);
    return 0;
}
