#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
char symbols[] = "<v>^<v>^<v>^";
string symb;
int l, r, n, dif;
char a[nmax][nmax];
char b[nmax][nmax];
void copyy(char source[nmax][nmax], char dest[nmax][nmax])
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            dest[i][j] = source[i][j];
}
char getNextRight(char ch)
{
    if (ch == '.') return '.';
    int poz;
    for (poz=3;; ++poz)
        if (ch == symbols[poz])
            break;
    return symbols[poz-1];
}
char getNextLeft(char ch)
{
    int poz;
    for (poz=3;; ++poz)
        if (ch == symbols[poz])
            break;
    return symbols[poz+1];
}
void rotateRight()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            int l, c;
            c = n - i + 1;
            l = j;
            char ch = getNextRight(a[i][j]);
            b[l][c] = ch;
        }
}
int main()
{
    cin>>n>>symb;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>a[i][j];
    for (auto x:symb)
        if (x == 'L')
            ++l;
        else
            ++r;
    copyy(a, b);
    if (l > r)
    {
        dif = l - r;
        dif %= 4;
        dif = 4 - dif;
        dif %= 4;
        for (int i=1; i<=dif; ++i)
        {
            rotateRight();
            copyy(b, a);
        }
    }
    else
    {
        dif = r - l;
        dif %= 4;
        for (int i=1; i<=dif; ++i)
        {
            rotateRight();
            copyy(b, a);
        }
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            cout<<b[i][j];
        cout<<'\n';
    }
    return 0;
}
