#include <bits/stdc++.h>
#define nmax 2005
using namespace std;
char s[nmax];
int ln;
int main()
{
    cin>>s;
    ln = strlen(s);
    int i = 0, j = ln-1;
    while (i <= ln/2)
    {
        if (s[i] >= s[j])
            s[j] = s[i];
        else
        {
            int k = j-1;
            while (s[k] == '9')
                s[k--] = '0';
            s[k] ++;
            s[j] = s[i];
        }
        ++i, --j;
    }
    cout<<s<<'\n';
    return 0;
}
