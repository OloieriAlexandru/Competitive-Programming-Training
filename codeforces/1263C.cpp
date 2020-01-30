#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int>st;
        st.insert(0);
        st.insert(1);
        int n;
        cin>>n;
        for (int i=1;i*i<=n;++i){
            st.insert(n/i);
            st.insert(n/(n/i));
        }
        st.insert(n/2);
        st.insert(n);

        cout<<st.size()<<'\n';
        for (auto x:st){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
