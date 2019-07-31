#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int st[nmax], dr[nmax], n, m, x;
stack<int>ans;
vector<int>anss;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>st[i]>>dr[i];
    cin>>m;
    int curr = 0;
    for (int i=1; i<=m; ++i)
    {
        cin>>x;
        while (!ans.empty() && dr[ans.top()-1] < x) ans.pop();
        while (curr < n && dr[curr] < x) ++curr;
        while (curr < n && (st[curr] <= x && x <= dr[curr] || dr[curr] < x))
        {
            if (dr[curr] < x)
            {
                ++curr;
                continue;
            }
            ans.push(curr+1);
            ++curr;
        }
        if (ans.empty())
            anss.push_back(-1);
        else
            anss.push_back(ans.top());
    }
    for (auto x:anss)
        cout<<x<<'\n';
    return 0;
}
