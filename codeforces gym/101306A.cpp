#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxx = 0, fv[10], ans = 0;
    memset(fv, 0, sizeof(fv));
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i)
    {
        int act = 1;
        while (i < s.size()-1 && s[i] == s[i+1])
            ++i, ++act;
        maxx = max(act, maxx);
    }
    for (int i=0;i<s.size();++i)
    {
        int act = 1;
        while (i < s.size()-1 && s[i] == s[i+1])
            ++i, ++act;
        if (act == maxx)
            ++fv[s[i]-'0'], ++ans;
    }
    cout<<ans<<'\n';
    for (int i=0;i<10;++i)
        while (fv[i])
        {
            --fv[i];
            for (int j=0;j<maxx;++j)
                cout<<i;
            cout<<'\n';
        }
    return 0;
}
