#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, k;
        vector<int>imp;
        cin>>n>>k;
        imp.clear();
        for (int i=1; i<=n; ++i)
        {
            cin>>x;
            if (x % 2 == 1)
                imp.push_back(i);
        }
        if (imp.size() < k)
        {
            cout<<"NO\n";
            continue;
        }
        if ((imp.size() - k)%2 == 1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for (int i=0; i<k-1; ++i)
            cout<<imp[i]<<' ';
        cout<<n<<'\n';
    }
    return 0;
}
