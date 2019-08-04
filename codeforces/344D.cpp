#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    stack<char>st;
    cin>>s;
    for (auto x:s)
    {
        if (st.empty())
            st.push(x);
        else
        if (st.top() == x)
            st.pop();
        else
            st.push(x);
    }
    if (st.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
