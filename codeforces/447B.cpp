#include <bits/stdc++.h>
#define nmax 27
using namespace std;
string s;
int n, c[nmax], maxx, ans;
int main()
{
    cin>>s;
    cin>>n;
    for (int i=1; i<=26; ++i)
    {
        cin>>c[i];
        maxx = max(maxx, c[i]);
    }
    for (int i=0;i<s.size();++i)
        ans += c[s[i]-'a'+1] * (i + 1);
    for (int i=1;i<=n;++i)
        ans += maxx * (i + s.size());
    cout<<ans<<'\n';
    return 0;
}
