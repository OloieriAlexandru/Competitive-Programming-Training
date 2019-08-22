#include <bits/stdc++.h>
using namespace std;
string s;
stack<int>ans;
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); ++i)
    {
        if (s[i] == '0')
           {if (!ans.empty())ans.pop();}
        else
            ans.push(i);
    }
    while (!ans.empty())
    {
        s[ans.top()] = '0';
        ans.pop();
    }
    cout<<s<<'\n';
    return 0;
}
