#include <bits/stdc++.h>
#define nmax 300005
#define lld long long
using namespace std;
int n, dif[nmax];
pair<int,int>s[nmax], t[nmax];
lld sum;
vector<pair<pair<int,int>,int>>ans;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&s[i].first);
        s[i].second = i;
    }
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&t[i].first);
        s[i].second = i;
    }
    sort(s+1,s+n+1);
    sort(t+1,t+n+1);
    for (int i=1; i<=n; ++i)
    {
        dif[i] = t[i].first - s[i].first;
        sum += dif[i];
        if (sum < 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    if (dif[1] < 0 || sum)
    {
        printf("NO\n");
        return 0;
    }
    stack<pair<int,int>>st;
    for (int i=1; i<=n; ++i)
    {
        if (!dif[i]) continue;
        if (dif[i] > 0)
        {
            st.push(make_pair(s[i].second, dif[i]));
            continue;
        }
        while (1)
        {
            if (st.empty()) break;
            dif[i] = abs(dif[i]);
            if (st.top().second <= abs(dif[i]))
            {
                ans.push_back(make_pair(make_pair(st.top().first, s[i].second),st.top().second));
                dif[i] -= st.top().second;
                st.pop();
            }
            else
            {
                ans.push_back(make_pair(make_pair(st.top().first, s[i].second),abs(dif[i])));
                st.top().second -= dif[i];
                dif[i] = 0;
            }
            if (!dif[i]) break;
        }
    }
    printf("YES\n%u\n", ans.size());
    for (auto x:ans)
        printf("%d %d %d\n", x.first.first, x.first.second, x.second);
    return 0;
}
