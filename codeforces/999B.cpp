#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n;
char s[nmax];
int main()
{
    cin>>n>>s;
    for (int i=1;i<=n;++i)
    {
        if (n % i == 0)
        {
            reverse(s,s+i);
        }
    }
    cout<<s<<'\n';
    return 0;
}
