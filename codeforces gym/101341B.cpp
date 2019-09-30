#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
char s[nmax];
int ln, cnt, poz, poz2;
bool ok()
{
    for (int i=0; i<ln; ++i)
        if (!strncmp(s+i,"happiness", 9))
            return false;
    return true;
}
int main()
{
    scanf("%s",s);
    ln = strlen(s);
    for (int i=0; i<ln; ++i)
    {
        if (!strncmp(s+i,"happiness", 9))
        {
            ++cnt;
            if (cnt == 1)
                poz = i;
            else
                poz2 = i;
        }
    }
    if (cnt > 2)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    if (cnt == 0)
    {
        for (int i=1; i<ln; ++i)
        {
            swap(s[0],s[i]);
            if (ok())
            {
                cout<<1<<' '<<i+1<<'\n';
                return 0;
            }
            swap(s[0],s[i]);
        }
        for (int i=3;i<ln;++i)
        {
            swap(s[1],s[i]);
            if (ok())
            {
                cout<<2<<' '<<i+1<<'\n';
                return 0;
            }
            swap(s[1],s[i]);
        }
    }
    else if (cnt == 1)
        cout<<poz+1<<' '<<poz+2<<'\n';
    else
        cout<<poz+1<<' '<<poz2+2<<'\n';
    return 0;
}
