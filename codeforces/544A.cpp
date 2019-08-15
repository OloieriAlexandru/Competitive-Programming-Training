#include <bits/stdc++.h>
#define nmax 30
using namespace std;
int n, fv[30], dif, nr = 0;
bool added[30];
string s;
int main()
{
    cin>>n;
    cin>>s;
    for (int i=0; i<s.size(); ++i)
        if (!fv[s[i]-'a'])
        {
            ++dif, fv[s[i]-'a'] = 1;
        }
    if (dif < n)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES";
    int i = 0;
    while (nr < n-1)
    {
        if (!added[s[i]-'a'])
        {
            added[s[i]-'a'] = true;
            cout<<'\n';
            cout<<s[i];
            ++nr;
        }
        else
            cout<<s[i];
        ++i;
    }
    while (added[s[i]-'a'])
        cout<<s[i], ++i;
    cout<<'\n';
    for (;i<s.size();++i)
        cout<<s[i];
    cout<<'\n';
    return 0;
}
