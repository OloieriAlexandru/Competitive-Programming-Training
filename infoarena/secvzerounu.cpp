#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("secvzerounu.in","r",stdin);
    freopen("secvzerounu.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        bool ok = false;
        if (s[0] == '0' && s.size() == 1)
            ok = true;
        if (s.size() >= 2 && s[0] == '0' && s[1] == '1')
            ok = true;
        if (ok)
            printf("Da\n");
        else
            printf("Nu\n");
    }
    return 0;
}
