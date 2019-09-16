#include <bits/stdc++.h>
using namespace std;
string s, s2;
int n, x;
int r = 2000000000, l = -2000000000;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>s>>x>>s2;
        if (s2 == "N")
        {
            if (s == ">")
                s = "<=";
            else
            if (s == "<")
                s = ">=";
            else
            if (s == "<=")
                s = ">";
            else
                s = "<";
        }
        if (s == ">")
            l = max(l, x+1);
        else
        if (s == ">=")
            l = max(l, x);
        else
        if (s == "<")
            r = min(r , x - 1);
        else
        if (s == "<=")
            r = min(r, x);
    }
    if (r < l)
        cout<<"Impossible\n";
    else
        cout<<l<<'\n';
    return 0;
}
