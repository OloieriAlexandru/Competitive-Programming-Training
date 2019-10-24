#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, x, a[nmax];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            a[x] = 1;
        }
        int ans = 0;
        while (true)
        {
            bool found = false;
            for (int i=1;i<=100;++i)
            {
                if (a[i])
                {
                    a[i] = 0;
                    ++i;
                    found = true;
                }
            }
            if (!found) break;
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
