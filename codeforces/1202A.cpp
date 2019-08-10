#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int a = -1, b = -1;
        for (int i=0; i<s2.size(); ++i)
            if (s2[i] == '1')
            {
                b = i;
                break;
            }
        for (int i=0; i<s1.size(); ++i)
            if (s1[i] == '1' && i >= b)
            {
                a = i;
                break;
            }
        if (a <= b)
            cout<<"0\n";
        else
            cout<<a-b<<'\n';
    }
    return 0;
}
