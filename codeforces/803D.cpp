#include <bits/stdc++.h>
using namespace std;
int k, ln, ans;
string s;
bool ok(int m)
{
    int nrr = 1, lst = -1, act = 0;
    for (int i=0;i<ln;++i)
    {
        ++act;
        if (act > m)
        {
            if (lst == -1) return false;
            ++nrr;
            act = i - lst;
            lst = -1;
        }
        if (s[i] == ' ' || s[i] == '-')lst = i;
    }
    return nrr <= k;
}
int main()
{
    cin>>k;
    cin.get();
    std::getline(cin, s);
    ln = s.size();
    int st = 1, dr = ln;
    while (st <= dr)
    {
        int m = ( st + dr ) / 2;
        if (ok(m))
            dr = m-1, ans = m;
        else
            st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
