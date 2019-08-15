#include <bits/stdc++.h>
using namespace std;
int n, fv[150000], x;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>x, ++fv[x];
    for (int i=1; i<150000; ++i)
    {
        if (!fv[i])
        {
            if (fv[i-1] > 1) fv[i] = 1;
            else if (fv[i+1])
                --fv[i+1], fv[i] = 1;
        }
        else if (fv[i-1] > 1) ++fv[i], --fv[i-1];
    }
    int ans = 0;
    for (int i=1; i<150000; ++i)
        if (fv[i]) ++ans;
    cout<<ans<<'\n';
    return 0;
}
