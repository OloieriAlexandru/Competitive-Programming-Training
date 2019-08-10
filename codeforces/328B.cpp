#include <bits/stdc++.h>
using namespace std;
int fv[26], fv2[26], ans = 999999999;
int main()
{
    string a, b;
    cin>>a>>b;
    for (auto &it : a)
    {
        if (it == '2') it = '5';
        if (it == '6') it = '9';
    }
    for (auto &it : b)
    {
        if (it == '2') it = '5';
        if (it == '6') it = '9';
    }
    for (auto x:a)
        ++fv[x-'0'];
    for (auto x:b)
        ++fv2[x-'0'];
    for (int i=0;i<10;++i)
    {
        if (!fv[i] || !fv2[i]) continue;
        ans = min(ans, fv2[i]/fv[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
