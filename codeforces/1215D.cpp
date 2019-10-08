#include <bits/stdc++.h>
using namespace std;
string      s;
int         n, l, r;
int main()
{
    cin>>n;
    cin>>s;
    for (int i=0; i<s.size(); ++i)
    {
        if (s[i] == '?')
        {
            if (i < s.size() / 2)
                l += 9;
            else
                r += 9;
        }
        else
        {
            if (i < s.size()/2)
                l += (s[i] - '0')*2;
            else
                r += (s[i] - '0')*2;
        }
    }
    if (abs((l-r)/2.0) > 1e-6)
        cout<<"Monocarp\n";
    else
        cout<<"Bicarp\n";
    return 0;
}
