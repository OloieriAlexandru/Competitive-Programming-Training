#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        for (auto &x:s1)
        {
            x = tolower(x);
            if (x == 'p') x = 'b';
            if (x == 'e') x = 'i';
        }
        for (auto &x:s2)
        {
            x = tolower(x);
            if (x == 'p') x = 'b';
            if (x == 'e') x = 'i';
        }
        if (s1 == s2)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
