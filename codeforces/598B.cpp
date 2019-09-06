#include <bits/stdc++.h>
using namespace std;
string s, cs;
int n, x, y, cnt, l;
int getPozAfter(int i, int j, int act, int cnt)
{
    if (act + cnt <= j) return act + cnt;
    int p = (act+cnt)-j;
    return i + p - 1;
}
int main()
{
    cin>>s;
    cs = s;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y>>cnt;
        --x, --y;
        l = y - x + 1;
        cnt = cnt % l;
        for (int j=x;j<=y;++j)
            cs[getPozAfter(x, y, j, cnt)] = s[j];
        for (int j=x;j<=y;++j)
            s[j] = cs[j];
    }
    cout<<s<<'\n';
    return 0;
}
