#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
char s[nmax];
int t, ln, ans, z, act;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        ln = strlen(s);
        ans = 0;
        z = 0;
        for (int i=0;i<ln;++i)
        {
            if (s[i] == '0')++z;
            else
            {
                act = 1;
                ++ans;
                for (int j=i+1;j<ln;++j)
                {
                    act *= 2;
                    act += (s[j]-'0');
                    if (z + j - i + 1 < act)
                        break;
                    ++ans;
                }
                z = 0;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
