#include <bits/stdc++.h>
using namespace std;
string s;
int n, k;
int main()
{
    cin>>n>>k;
    cin>>s;
    if (n == 1 && k)
    {
        cout<<"0\n";
        return 0;
    }
    if (!k)
    {
        cout<<s<<'\n';
        return 0;
    }
    if (s[0] != '1')
        s[0] = '1', --k;
    for (int i=1;i<n;++i)
    {
        if (k && s[i] != '0')
            s[i] = '0', --k;
    }
    cout<<s<<'\n';
    return 0;
}
