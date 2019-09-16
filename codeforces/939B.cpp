#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
lld ans1, ans2, boxes[nmax], act, n, maxx;
int k;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=k;++i)
        cin>>boxes[i];
    for (int i=1;i<=k;++i)
    {
        act = n / boxes[i];
        act *= boxes[i];
        if (act > maxx)
        {
            maxx = act;
            ans1 = i;
            ans2 = act / boxes[i];
        }
    }
    if (!ans1) ans1 = 1;
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
