#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    for (int i=0;i<s.size();++i)
    {
        char ch = s[i];
        int cnt = 1;
        while (i < s.size()-1 && s[i] == s[i+1])
            ++i, ++cnt;
        cout<<ch<<cnt;
    }
    cout<<'\n';
    return 0;
}
