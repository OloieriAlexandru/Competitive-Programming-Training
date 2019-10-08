#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
char s[nmax];
int t;
int main()
{
    cin>>t;
    cin.get();
    while(t--)
    {
        cin.getline(s, nmax);
        char* p = strtok(s, " ");
        int cnt = 0;
        while (p)
        {
            if (strlen(p) == 1)
            {
                cout<<p<<"ay ";
                ++cnt;
                p = strtok(NULL, " ");
                continue;
            }
            if (!cnt)
                *(p+1) = *(p+1)- 'a' + 'A', *p = *p - 'A' + 'a';
            cout<<p+1<<p[0]<<"ay ";
            ++cnt;
            p = strtok(NULL, " ");
        }
        cout<<'\n';
    }
    return 0;
}
