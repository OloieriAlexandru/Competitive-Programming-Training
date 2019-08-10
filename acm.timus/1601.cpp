#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int i=0;
    while (cin.get(c))
    {
        if ((c >= 'A') && (c <= 'Z'))
        {
            i++;
            if (('A' <= c) && (c <= 'Z') && (i != 1))
                c += 'a' - 'A', ++i;
        }
        else if ((c == 46) || (c == 33) || (c == 63)) i = 0;
        cout<<c;
    }
    return 0;
}
