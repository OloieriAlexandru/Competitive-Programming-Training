#include <bits/stdc++.h>
#define nmax 26
using namespace std;
int fv1[nmax], fv2[nmax];
string s, t;
bool ok;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>s>>t;
        for (int i=0;i<s.size();++i)
            ++fv1[s[i]-'a'], ++fv2[t[i]-'a'];
        ok = false;
        for (int i=0; i<26; ++i)
        {
            if (fv1[i] && fv2[i])
                ok = true;
            fv1[i] = fv2[i] = 0;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
