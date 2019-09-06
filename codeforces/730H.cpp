#include <bits/stdc++.h>
#define nmax 105
using namespace std;
string s[nmax], pattern;
int n, m, index[nmax], ln[nmax];
bool ind[nmax], ok;
bool check()
{
    int nr = 0;
    for (int i=1; i<=n; ++i)
    {
        if (ind[i]) continue;
        bool ok = true;
        if (ln[1] != s[i].size()) continue;
        for (int j=0; j<ln[1]; ++j)
        {
            if (s[i][j] != pattern[j] && pattern[j] != '?')
            {
                ok = false;
                break;
            }
        }
        if (ok) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>s[i];
    }
    for (int i=1; i<=m; ++i)
    {
        cin>>index[i];
        ln[i] = s[index[i]].size();
        ind[index[i]] = true;
        if (ln[i] != ln[1])
        {
            cout<<"No\n";
            return 0;
        }
    }
    for (int i=0; i<ln[1]; ++i)
    {
        bool ok = true;
        char ch;
        ch = s[index[1]][i];
        for (int j=2; j<=m; ++j)
        {
            if (ch == s[index[j]][i]) continue;
            ok = false;
        }
        if (ok)
            pattern.push_back(ch);
        else
            pattern.push_back('?');
    }
    ok = check();
    if (ok)
        cout<<"Yes\n"<<pattern<<'\n';
    else
        cout<<"No\n";
    return 0;
}
