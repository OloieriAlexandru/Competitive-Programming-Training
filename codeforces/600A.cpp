#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
char s[nmax], sep[]=",;", cs[nmax*2];
int ln, total, tsep, cln;
vector<string>ans1, ans2;
bool ok(char *p)
{
    int ln = strlen(p);
    if (ln == 1 && p[0] == '0') return true;
    if (p[0] == '0') return false;
    if (!(p[0] >= '1' && p[0] <= '9')) return false;
    for (int i=1; i<ln; ++i)
        if (!(p[i] >= '0' && p[i] <= '9')) return false;
    return true;
}
int main()
{
    cin>>s;
    ln = strlen(s);
    for (int i=0; i<ln; ++i)
    {
        total = 0, tsep = 0;
        if (i > 0)
        {
            ++total;
            if (s[i-1] == ',' || s[i-1] == ';')
                ++tsep;
        }
        ++total;
        if (s[i] == ',' || s[i] == ';')
            ++tsep;

        if (total == tsep)
            cs[cln++] = '!';
        cs[cln++] = s[i];
        if (i+1 == ln && (s[i] == ',' || s[i] == ';'))
            cs[cln++] = '!';
    }
    char *p = strtok(cs, sep);
    while (p)
    {
        if (p[0] == '!')
            ans2.push_back("emptyyyyy");
        else
        {
            if (ok(p))
                ans1.push_back(string(p));
            else
                ans2.push_back(string(p));
        }
        p = strtok(NULL, sep);
    }
    if (!ans1.size())
        cout<<"-\n";
    else
    {
        cout<<'"';
        for (int i=0; i<ans1.size(); ++i)
        {
            cout<<ans1[i];
            if (i+1 != ans1.size())
                cout<<',';
        }
        cout<<"\"\n";
    }
    if (!ans2.size())
        cout<<"-\n";
    else
    {
        cout<<'"';
        for (int i=0; i<ans2.size(); ++i)
        {
            if (ans2[i] != (string)"emptyyyyy")
                cout<<ans2[i];
            if (i+1 != ans2.size())
                cout<<',';
        }
        cout<<"\"\n";
    }
    return 0;
}
