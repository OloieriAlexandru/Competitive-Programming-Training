#include <bits/stdc++.h>
#define nmax 10
using namespace std;
int n, ans[10];
string s;
int main()
{
    cin>>n;
    cin>>s;
    for (int i=0; i<s.size(); ++i)
    {
        if (s[i] == 'L')
        {
            for (int j=0; j<10; ++j)
                if (!ans[j])
                {
                    ans[j] = 1;
                    break;
                }
        }
        else if (s[i] == 'R')
        {
            for (int j=9; j>=0; --j)
                if (!ans[j])
                {
                    ans[j] = 1;
                    break;
                }
        }
        else
            ans[s[i]-'0'] = 0;
    }
    for (int i=0; i<10; ++i)
        cout<<ans[i];
    cout<<'\n';
    return 0;
}
