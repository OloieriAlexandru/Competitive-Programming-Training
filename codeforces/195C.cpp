#include <bits/stdc++.h>
#define nmax 55
using namespace std;
char s[nmax];
stack<string>st;
string message, currentCatch, toCatch;
int n, ln, levelLowerThan = -1, level;
bool printedAns;
int main()
{
    cin>>n;
    cin.get();
    for (int i=1; i<=n; ++i)
    {
        cin.getline(s, nmax);
        if (printedAns) continue;
        ln = strlen(s);
        bool ok = false;
        for (int j=0; j<ln&&!ok; ++j)
        {
            if (s[j] == '"')
            {
                for (int k=j+1; k<ln; ++k)
                {
                    if (s[k] == '"')
                    {
                        s[k] = '\0';
                        message = string(s+j+1);
                        ok = true;
                        break;
                    }
                }
            }
        }
        char *p = strtok(s, " (),\"");
        if (!p) continue;
        if (!strcmp(p, "try"))
        {
            ++level;
            continue;
        }
        if (!strcmp(p, "throw"))
        {
            if (levelLowerThan != -1)continue;
            p = strtok(NULL, " (),\"");
            toCatch = string(p);
            levelLowerThan = level-1;
            continue;
        }
        if (!strcmp(p, "catch"))
        {
            --level;
            if (level <= levelLowerThan)
            {
                p = strtok(NULL, " (),\"");
                currentCatch = string(p);
                if (toCatch == currentCatch)
                {
                    printf("%s\n", message.c_str());
                    printedAns = true;
                }
                --levelLowerThan;
            }
        }
    }
    if (!printedAns) printf("Unhandled Exception\n");
    return 0;
}
