#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<char>anss;
stack<char>st;
char ch;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>ch;
        if (st.empty())
            st.push(ch);
        else
        {
            if (st.top() == ch && st.size() % 2 == 1)
            {
                ++ans;
                continue;
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        anss.push_back(st.top());
        st.pop();
    }
    reverse(anss.begin(), anss.end());
    if (anss.size() % 2)
    {
        ++ans;
        anss.pop_back();
    }
    cout<<ans<<'\n';
    for (auto x:anss)
        cout<<x;
    cout<<'\n';
    return 0;
}
