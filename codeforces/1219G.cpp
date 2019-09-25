#include <bits/stdc++.h>
#define lld long long
using namespace std;
vector<vector<int>>a;
vector<lld>sumr, sumc;
int n, m;
lld ans, act;
int main()
{
    scanf("%d %d",&n,&m);
    a.resize(n+1);
    for (int i=1; i<=n; ++i)
        a[i].resize(m+1);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d",&a[i][j]);
    sumr.resize(n+1);
    sumc.resize(m+1);
    for (int i=1; i<=n; ++i)
    {
        act = 0;
        for (int j=1; j<=m; ++j)
            act += a[i][j];
        sumr[i] = act;
    }
    for (int j=1; j<=m; ++j)
    {
        act = 0;
        for (int i=1; i<=n; ++i)
            act += a[i][j];
        sumc[j] = act;
    }
    if (n <=4 || m <= 4)
    {
        for (int i=1; i<=n; ++i)
            ans += sumr[i];
        printf("%lld\n", ans);
        return 0;
    }
    vector<lld>nw = sumr;
    auto it = nw.begin();
    ++it;
    sort(it, nw.end(), [](lld a, lld b)
    {
        return a>b;
    });
    for (int i=1; i<=4; ++i)
        ans += nw[i];
    nw = sumc;
    it = nw.begin();
    ++it;
    sort(it, nw.end(), [](lld a, lld b)
    {
        return a > b;
    });
    act = 0;
    for (int i=1; i<=4; ++i)
        act += nw[i];
    ans = max(ans, act);

    // --------------------------
    for (int i=1; i<=n; ++i)
    {
        nw.clear();
        for (int j=1; j<=m; ++j)
        {
            act = sumc[j] - a[i][j];
            nw.push_back(act);
        }
        sort(nw.begin(), nw.end(), [](lld a, lld b)
        {
            return a>b;
        });
        act = sumr[i];
        for (int j=0; j<3; ++j)
            act += nw[j];
        ans = max(ans, act);
    }

    for (int j=1; j<=m; ++j)
    {
        nw.clear();
        for (int i=1; i<=n; ++i)
        {
            act = sumr[i] - a[i][j];
            nw.push_back(act);
        }
        sort(nw.begin(), nw.end(), [](lld a, lld b)
        {
            return a>b;
        });
        act = sumc[j];
        for (int i=0; i<3; ++i)
            act += nw[i];
        ans = max(ans, act);
    }


    priority_queue<lld, vector<lld>, greater<lld> > pq;
    if (n <= m)
    {
        for (int i=1; i<n; ++i)
            for (int j=i+1; j<=n; ++j)
            {
                for (int k=1; k<=m; ++k)
                {
                    act = sumc[k] - a[i][k] - a[j][k];
                    pq.push(act);
                    if (pq.size() > 2)
                        pq.pop();
                }
                act = sumr[i] + sumr[j] + pq.top();
                pq.pop();
                act += pq.top();
                pq.pop();
                ans = max(ans, act);
            }
    }
    else
    {
        for (int i=1; i<m; ++i)
            for (int j=i+1; j<=m; ++j)
            {
                for (int k=1; k<=n; ++k)
                {
                    act = sumr[k] - a[k][i] - a[k][j];
                    pq.push(act);
                    if (pq.size() > 2)
                        pq.pop();
                }
                act = sumc[i] + sumc[j] + pq.top();
                pq.pop();
                act += pq.top();
                pq.pop();
                ans = max(ans, act);
            }
    }

    printf("%lld\n", ans);
    return 0;
}
