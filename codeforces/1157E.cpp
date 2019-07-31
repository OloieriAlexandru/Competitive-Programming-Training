#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, x, a[nmax];
multiset<int>st;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        st.insert(x);
    }
    for (int i=1;i<=n;++i)
    {
        auto it1 = st.lower_bound((n-a[i]));
        auto it2 = st.begin();
        int v1;
        if (it1 == st.end())
            v1 = 999999999;
        else
            v1 = ( a[i] + *it1 ) % n;
        int v2 = ( a[i] + *it2 ) % n;
        if (v1 < v2)
        {
            cout<<v1<<' ';
            st.erase(it1);
        }
        else
        {
            cout<<v2<<' ';
            st.erase(it2);
        }
    }
    cout<<'\n';
    return 0;
}
