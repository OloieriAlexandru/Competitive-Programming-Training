#include <bits/stdc++.h>
using namespace std;
int n, k, x;
set<int>st;
queue<int>q;
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if (st.count(x)) continue;
        if (q.size() == k)
        {
            st.erase(q.front());
            q.pop();
        }
        q.push(x);
        st.insert(x);
    }
    printf("%d\n", q.size());
    vector<int>ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans)
        printf("%d ", x);
    return 0;
}
