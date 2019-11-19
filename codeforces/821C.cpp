#include <bits/stdc++.h>
using namespace std;
stack<int>st;
int main()
{
    int n, ans=0;
    cin>>n;
    int nn = 2*n, nw=0;
    while(nn--)
    {
        string cmd;
        cin>>cmd;
        if (cmd=="add")
        {
            int x;
            cin>>x;
            st.push(x);
        }
        else
        {
            ++nw;
            if (st.empty()){
                continue;
            }
            if (nw==st.top())
                st.pop();
            else
            {
                ++ans;
                while (!st.empty())
                    st.pop();
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
