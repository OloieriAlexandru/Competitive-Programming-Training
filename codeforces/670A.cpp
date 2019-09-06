#include <bits/stdc++.h>
#define inf 999999999
using namespace std;
int week[8];
int ans1 = -1, ans2 = inf, act, n;
int main()
{
    week[6] = week[7] = 1;
    cin>>n;
    for (int i=1;i<=7;++i)
    {
        // anul incepe cu ziua i
        act = 2 * (n / 7);
        int r = n % 7;
        for (int j=i;j<i+r;++j)
            if (week[j])
                ++act;
        ans1 = max(ans1, act);
        ans2 = min(ans2, act);
    }
    cout<<ans2<<' '<<ans1<<'\n';
    return 0;
}
