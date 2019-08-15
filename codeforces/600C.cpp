#include <bits/stdc++.h>
using namespace std;
string s;
string p, prevv;
int fv[26];
int main()
{
    cin>>s;
    for (auto x:s)
        ++fv[x-'a'];
    if (s.size() % 2)
    {
        int add = -1, cnt;
        char af;
        vector<int>chg;
        for (int i=0; i<26; ++i)
            if (fv[i] % 2)
                chg.push_back(i);
        int st = 0, dr = chg.size()-1;
        while (st <= dr)
        {
            if (st == dr)
            {
                af = chg[st] + 'a';
                break;
            }
            ++fv[chg[st]], --fv[chg[dr]];
            ++st, --dr;
        }
        for (int i=0; i<26; ++i)
        {
            if (fv[i]%2) af = (char)(i+'a');
            cnt = fv[i]/2;
            for (int j=0; j<cnt; ++j)
                p.push_back((char)(i+'a'));
        }
        prevv = p;
        reverse(prevv.begin(), prevv.end());
        for (auto x:p)
            cout<<x;
        cout<<af;
        for (auto x:prevv)
            cout<<x;
        cout<<'\n';
    }
    else
    {
        int add = -1, cnt;
        vector<int>chg;
        for (int i=0; i<26; ++i)
            if (fv[i] % 2)
                chg.push_back(i);
        int st = 0, dr = chg.size()-1;
        while (st < dr)
        {
            ++fv[chg[st]], --fv[chg[dr]];
            ++st, --dr;
        }
        for (int i=0; i<26; ++i)
        {
            cnt = fv[i]/2;
            for (int j=0; j<cnt; ++j)
                p.push_back((char)(i+'a'));
        }
        prevv = p;
        reverse(prevv.begin(), prevv.end());
        for (auto x:p)
            cout<<x;
        for (auto x:prevv)
            cout<<x;
        cout<<'\n';
    }
    return 0;
}
