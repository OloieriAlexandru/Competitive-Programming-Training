#include <bits/stdc++.h>
#define lld long long
using namespace std;
int n, x, nrn, nrp;
lld ans1, ans2;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (x < 0)
        {
            swap(nrn, nrp);
            ++nrn;
        }
        else
            ++nrp;
        ans1 += nrn;
        ans2 += nrp;
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
