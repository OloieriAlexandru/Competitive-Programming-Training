#include <bits/stdc++.h>
using namespace std;
int ln, ans, a, b;
string s;
int main()
{
    cin>>ln;
    cin>>s;
    for (int i=0;i<ln;i+=2)
    {
        if (s[i] == 'a')
            ++a;
        else
            ++b;
        if (s[i+1] == 'a')
            ++a;
        else
            ++b;
        if (a > b)
        {
            ++ans;
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i+1] = 'b';
            a = b;
        }
        else
        if (a < b)
        {
            ++ans;
            if (s[i] == 'b')
                s[i] = 'a';
            else
                s[i+1] = 'a';
            b = a;
        }
    }
    cout<<ans<<'\n'<<s<<'\n';
    return 0;
}
