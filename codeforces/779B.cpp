#include <bits/stdc++.h>
using namespace std;
string s;
int k, ans, cnt, tr;
int main()
{
    cin>>s>>k;
    reverse(s.begin(), s.end());
    while (tr < s.size() && s[tr] == '0')
        ++cnt, ++tr;
    if (cnt >= k)
    {
        cout<<"0\n";
        return 0;
    }
    while (tr < s.size())
    {
        if (s[tr] != '0')
            ++ans;
        else
        {
            ++cnt;
            if (cnt >= k)
            {
                cout<<ans<<'\n';
                return 0;
            }
        }
        ++tr;
    }
    cout<<s.size()-1<<'\n';
    return 0;
}
