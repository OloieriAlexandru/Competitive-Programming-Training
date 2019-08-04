#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
char s[nmax];
int p, n;
int main()
{
    cin>>n>>p;
    cin>>(s+2);
    for (int i=n+1; i>=2; --i)
    {
        for (int j=s[i]-'a'+1; j<p; ++j)
        {
            char ch = j + 'a';
            if (ch == s[i-1] || ch == s[i-2]) continue;
            s[i] = ch;
            bool ok = true;
            for (int k=i+1; k<=n+1; ++k)
            {
                bool fnd = false;
                for (int l=0; l<p; ++l)
                {
                    char chh = l + 'a';
                    if (chh == s[k-1] || chh == s[k-2]) continue;
                    s[k] = chh;
                    fnd = true;
                    break;
                }
                if (!fnd)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                cout<<(s+2)<<'\n';
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
