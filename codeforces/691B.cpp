#include <bits/stdc++.h>
using namespace std;
bool sim[128];
void sett()
{
    sim['a'] = false;
    sim['b'] = true;
    sim['c'] = false;
    sim['d'] = true;
    sim['e'] = false;
    sim['f'] = false;
    sim['g'] = false;
    sim['h'] = false;
    sim['i'] = false;
    sim['j'] = false;
    sim['k'] = false;
    sim['l'] = false;
    sim['m'] = false;
    sim['n'] = false;
    sim['o'] = true;
    sim['p'] = true;
    sim['q'] = true;
    sim['r'] = false;
    sim['s'] = false;
    sim['t'] = false;
    sim['u'] = false;
    sim['v'] = true;
    sim['w'] = true;
    sim['x'] = true;
    sim['y'] = false;
    sim['z'] = false;
    sim['A'] = true;
    sim['B'] = false;
    sim['C'] = false;
    sim['D'] = false;
    sim['E'] = false;
    sim['F'] = false;
    sim['G'] = false;
    sim['H'] = true;
    sim['I'] = true;
    sim['J'] = false;
    sim['K'] = false;
    sim['L'] = false;
    sim['M'] = true;
    sim['N'] = false;
    sim['O'] = true;
    sim['P'] = false;
    sim['Q'] = false;
    sim['R'] = false;
    sim['S'] = false;
    sim['T'] = true;
    sim['U'] = true;
    sim['V'] = true;
    sim['W'] = true;
    sim['X'] = true;
    sim['Y'] = true;
    sim['Z'] = false;
}
int main()
{
    sett();
    string s;
    cin>>s;
    bool ok = true;
    for (auto x:s)
        if (!sim[x])
    {
        ok = false;
        break;
    }
    if (ok)
    {
        int st = 0, dr = s.size()-1;
        while (st < dr)
        {
            if (s[st] == 'b' && s[dr] != 'd' || s[st] == 'd' && s[dr] != 'b')
            {
                ok = false;
                break;
            }
            if (s[st] == 'p' && s[dr] != 'q' || s[st] == 'q' && s[dr] != 'p')
            {
                ok = false;
                break;
            }
            if (s[st] != s[dr] && !strchr("bdpq", s[st])) ok = false;
            ++st, --dr;
        }
        if (s.size()%2)
        {
            int m = s.size()/2;
            if (s[m] == 'p' || s[m] == 'q' || s[m] == 'b' || s[m] == 'd') ok = false;
        }
    }
    if (ok)
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
    return 0;
}
