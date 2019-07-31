#include <bits/stdc++.h>
#define nmax 105
using namespace std;
char s1[nmax], s2[nmax];
int ln1, ln2;
int fv1[26], fv2[26];
int main()
{
    cin>>s1>>s2;
    ln1 = strlen(s1);
    ln2 = strlen(s2);
    bool ok1 = true, ok2 = true;
    for (int i=0; i<ln1; ++i)
        ++fv1[s1[i]-'a'];
    for (int i=0; i<ln2; ++i)
        ++fv2[s2[i]-'a'];
    for (int i=0; i<26; ++i)
        if (fv1[i] < fv2[i])
            ok1 = false;
    int act = 0;
    char *p1 = s1;
    --p1;
    while (act < ln2 && p1)
    {
        p1 = strchr(p1+1,s2[act]);
        if (!p1) break;
        ++act;
    }
    if (act < ln2) ok2 = false;
    swap(ok1,ok2);
    if (ok1 && ln1 >= ln2)
        cout<<"automaton\n";
    else if (ok2 && ln1 == ln2)
        cout<<"array\n";
    else if (ok2)
        cout<<"both\n";
    else
        cout<<"need tree\n";
    return 0;
}
