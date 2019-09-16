#include <bits/stdc++.h>
#define nmax 300003
using namespace std;
int n, nn;
string cs, t;
char s[nmax];
void check()
{
    for (int i=0;i<nn-1;++i)
        if (s[i] == cs[0] && s[i+1] == cs[1])
            return;
        else if (s[i] == t[0] && s[i+1] == t[1])
            return;
    cout<<"YES\n";
    cout<<s<<'\n';
    exit(0);
}
int main()
{
    cin>>n;
    nn = n * 3;
    cin>>cs>>t;
    for (int i=0;i<3;++i)
        for (int j=0;j<3;++j)
            for (int k=0;k<3;++k)
    {
        if (i == j) continue;
        if (i == k) continue;
        if (j == k) continue;
        char a = i + 'a';
        char b = j + 'a';
        char c = k + 'a';
        for (int tr = 0; tr < nn; ++tr)
        {
            if (tr%3==0)
                s[tr] = a;
            else
            if (tr%3==1)
                s[tr] = b;
            else
                s[tr] = c;
        }
        check();
        for (int tr = 0; tr < n; ++tr)
            s[tr] = a;
        for (int tr = n; tr < 2 * n; ++tr)
            s[tr] = b;
        for (int tr = 2 * n; tr < nn; ++tr)
            s[tr] = c;
        check();
    }
    printf("NO\n");
    return 0;
}
