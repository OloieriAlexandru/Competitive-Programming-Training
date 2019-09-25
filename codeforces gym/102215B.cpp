#include <bits/stdc++.h>
using namespace std;
string s[2];
string ans[2];
int cnt1, cnt2, cnt3, cnt4;
int main()
{
    cin>>s[0];
    cin>>s[1];
    for (int i=0; i<s[0].size(); ++i)
        if (s[0][i] == '#' && s[1][i] == '#')
            ++cnt1;
        else if (s[0][i] == '#')
            ++cnt2;
        else if (s[1][i] == '#')
            ++cnt3;
        else
            ++cnt4;
    if (!cnt1 && !cnt3)
    {
        cout<<"YES\n";
        sort(s[0].begin(), s[0].end());
        cout<<s[0]<<'\n';
        cout<<s[1]<<'\n';
        return 0;
    }
    if (!cnt1 && !cnt2)
    {
        cout<<"YES\n";
        sort(s[1].begin(), s[1].end());
        cout<<s[0]<<'\n';
        cout<<s[1]<<'\n';
        return 0;
    }
    if (cnt1)
    {
        for (int i=1; i<=cnt2; ++i)
        {
            ans[0].push_back('#');
            ans[1].push_back('.');
        }
        for (int i=1; i<=cnt1; ++i)
        {
            ans[0].push_back('#');
            ans[1].push_back('#');
        }
        for (int i=1; i<=cnt3; ++i)
        {
            ans[0].push_back('.');
            ans[1].push_back('#');
        }
        for (int i=1; i<=cnt4; ++i)
        {
            ans[0].push_back('.');
            ans[1].push_back('.');
        }
        cout<<"YES\n";
        cout<<ans[0]<<'\n';
        cout<<ans[1]<<'\n';
    }
    else
        cout<<"NO\n";
    return 0;
}
