#include <bits/stdc++.h>
using namespace std;
int n = 3, m = 10, l, c;
string s[3];
int main()
{
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
    {
        if (s[i][j] == '=')
        {
            l = i, c = j;
            goto there;
        }
    }
    there:
    bool af = false;
    for (int i=c+1;i<m;++i)
    {
        if (s[l][i] != '.')
        {
            cout<<s[l][i]<<'\n';
            af = true;
            break;
        }
    }
    if (!af)
        cout<<"You shall pass!!!\n";
    return 0;
}
