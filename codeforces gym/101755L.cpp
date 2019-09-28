#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
char ch, s[nmax];
int nxt[nmax][26], ind, act, ln, q, more;
string op;
bool nt;
vector<int>poz;
int main()
{
    //freopen("out.txt","w",stdout);
    cin>>(s+1);
    ln = strlen(s+1);
    for (int j=0; j<26; ++j)
    {
        nxt[ln][j] = -1;
        for (int i=ln-1; i>=0; --i)
        {
            if (s[i+1]== (char)(j+'a'))
                nxt[i][j] = i+1;
            else
                nxt[i][j] = nxt[i+1][j];
        }
    }
    cin>>q;
    poz.push_back(0);
    for (int qq=1; qq<=q; ++qq)
    {
        cin>>op;
        if (op == (string)"push")
        {
            cin>>ch;
            if (nt)
            {
                ++more;
                cout<<"NO\n";
            }
            else
            {
                act = poz.back();
                if (nxt[act][ch-'a'] == -1)
                {
                    nt = true;
                    more = 1;
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                    poz.push_back(nxt[act][ch-'a']);
                }
            }
        }
        else
        {
            if (nt)
            {
                --more;
                if (!more)
                {
                    nt = false;
                    cout<<"YES\n";
                }
                else
                    cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
                poz.pop_back();
            }
        }
    }
    return 0;
}
