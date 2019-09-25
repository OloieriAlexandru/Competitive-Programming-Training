#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
char s[nmax];
int ln, index, stri;
void printFromString(int start, int endd, bool quotes)
{
    int st = start;
    int dr = endd;
    if (quotes)++st, --dr;
    cout<<'<';
    while(st <= dr)
        cout<<s[st++];
    cout<<">\n";
}
int main()
{
    cin.getline(s, nmax);
    ln = strlen(s);
    while (index < ln)
    {
        if (s[index] == ' ')
        {
            ++index;
            continue;
        }
        if (s[index] == '\"')
        {
            stri = index;
            ++index;
            while (s[index] && s[index] != '\"')
                ++index;
            printFromString(stri, index, true);
            ++index;
        }
        else
        {
            stri = index;
            while (s[index] && s[index] != ' ')
                ++index;
            printFromString(stri, index-1, false);
        }
    }
    return 0;
}
