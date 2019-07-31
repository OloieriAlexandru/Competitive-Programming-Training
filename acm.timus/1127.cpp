#include <bits/stdc++.h>
using namespace std;
int v[256], cnt[10005], ans, n;
string s;
void doo(int a, int b, int c, int d)
{
    int curr = a * 1000 + b * 100 + c * 10 + d;
    int curr1 = b * 1000 + c * 100 + d * 10 + a;
    int curr2 = c * 1000 + d * 100 + a * 10 + b;
    int curr3 = d * 1000 + a * 100 + b * 10 + c;
    ++cnt[curr];
    ++cnt[curr1];
    ++cnt[curr2];
    ++cnt[curr3];
    ans = max(ans, cnt[curr]);
}
int main()
{
    v['A'] = 0;
    v['B'] = 1;
    v['C'] = 2;
    v['G'] = 3;
    v['O'] = 4;
    v['R'] = 5;
    v['S'] = 6;
    v['V'] = 7;
    v['W'] = 8;
    v['Y'] = 9;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        doo(v[s[0]],v[s[2]],v[s[3]],v[s[1]]);
        doo(v[s[0]],v[s[1]],v[s[3]],v[s[2]]);
        doo(v[s[0]],v[s[4]],v[s[3]],v[s[5]]);
        doo(v[s[0]],v[s[5]],v[s[3]],v[s[4]]);
        doo(v[s[5]],v[s[2]],v[s[4]],v[s[1]]);
        doo(v[s[5]],v[s[1]],v[s[4]],v[s[2]]);
    }
    cout<<ans<<'\n';
    return 0;
}
