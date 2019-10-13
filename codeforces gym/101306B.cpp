#include <bits/stdc++.h>
using namespace std;
string s;
int n, h, m, mars, other, ans;
int main()
{
    cin>>n>>h>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        for (auto &x:s)
            x = tolower(x);
        if (s == "mars")
            ++mars;
        else
            ++other;
    }
    if (other >= m)
        other -= m, m = 0;
    else
        ans += (m-other), other = 0;
    if (other + mars >= h)
        cout<<ans<<'\n';
    else
    {
        ans += h - (other + mars);
        cout<<ans<<'\n';
    }
    return 0;
}
