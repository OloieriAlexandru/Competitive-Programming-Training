#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
char s[nmax], t[nmax];
int ln;
int main()
{
    cin>>s;
    cin>>t;
    ln = strlen(s);
    int l = 0, r = ln-1;
    while (l < ln && s[l] == t[l])
        ++l;
    if (l == ln)
    {
        cout<<"YES\n";
        return 0;
    }
    while (r > l && s[r] == t[r])
        --r;
    reverse(t+l,t+r+1);
    if (!strcmp(s,t))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
