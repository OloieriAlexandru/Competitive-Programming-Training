#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    char ch = s[0];
    for (auto x:s)
        if (x <= ch)
        {
            ch = x;
            cout<<"Mike\n";
        }
        else cout<<"Ann\n";
    return 0;
}
