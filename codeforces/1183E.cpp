#include <bits/stdc++.h>
using namespace std;
queue<string>q;
int n, k, curr = 1, ans;
string act, nw, ts;
unordered_set<string>st;
int main()
{
    cin>>n>>k;
    cin>>act;
    q.push(act);
    while (!q.empty())
    {
        if (curr >= k) break;
        nw = q.front();
        q.pop();
        for (int i=0;i<nw.size();++i)
        {
            ts = nw;
            ts.erase(ts.begin() + i);
            if (!st.count(ts))
            {
                ++curr;
                st.insert(ts);
                ans += (n - ts.size());
                q.push(ts);
            }
            if (curr >= k) break;
        }
    }
    if (curr < k)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}
