#include <bits/stdc++.h>
#define lmax 40
using namespace std;
int year, n, q, ln, ln2;
char s[lmax];
vector<string>teams;
bool checkNum(char s[], int ln)
{
    if (ln < 2) return false;
    if (s[ln-2] == '#') return true;
    return false;
}
bool checkNum(string s, int ln)
{
    if (ln < 2) return false;
    if (s[ln-2] == '#') return true;
    return false;
}
bool teamExists()
{
    ln = strlen(s);
    bool hasNum = checkNum(s, ln);
    for (auto x:teams)
    {
        ln2 = x.size();
        bool num = checkNum(x, ln2);
        if (hasNum && !num) continue;
        if (!hasNum && num) continue;
        if (!hasNum && !num) continue;
        if (ln2 != ln) continue;
        bool ok = true;
        for (int i=0; i<ln-2; ++i)
        {
            if (s[i] != x[i])
            {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}
int main()
{
    cin >> year >> n >> q;
    cin.get();
    for (int i=1; i<=n; ++i)
    {
        cin.getline(s, lmax);
        if (teamExists()) continue;
        string add(s);
        teams.push_back(add);
    }
    cout<<teams[q]<<'\n';
    return 0;
}
