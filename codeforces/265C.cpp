#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
int ans[nmax], n;
string s;
vector<int>v1, v2;
int main()
{
    cin>>s;
    n = s.size();
    for (unsigned int tr = 0; tr < n;++tr)
    {
        if (s[tr] == 'l')
            v1.push_back(tr+1);
        else
            v2.push_back(tr+1);
    }
    reverse(v1.begin(), v1.end());
    for (auto x:v2)
        cout<<x<<'\n';
    for (auto x:v1)
        cout<<x<<'\n';
    cout<<'\n';
    return 0;
}
