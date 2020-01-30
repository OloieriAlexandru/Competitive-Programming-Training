#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,ans=0;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1;
        s2=s1;
        reverse(s2.begin(),s2.end());
        ans += (s1 == s2 ? 1 : 0);
    }
    cout<<ans<<'\n';
    return 0;
}
