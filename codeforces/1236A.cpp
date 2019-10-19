#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, ans1, ans2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int ca = a, cb = b, cc = c;

        ans1 = 0, ans2 = 0;

        while (a && b > 1)
            ans1 += 3, --a, b-=2;
        while (b && c > 1)
            ans1 += 3, --b, c-=2;

        a = ca, b = cb, c = cc;
        while (b && c > 1)
            ans2 += 3, --b, c-=2;
        while (a && b > 1)
            ans2 += 3, --a, b-=2;

        cout<<max(ans1, ans2)<<'\n';
    }
    return 0;
}
