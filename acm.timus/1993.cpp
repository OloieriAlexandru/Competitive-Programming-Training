#include <bits/stdc++.h>
using namespace std;
vector<char>obj, sub, ver;
char ch;
bool ok;
int cnt;
int main()
{
    while(cin.get(ch))
    {
        if (ch == ',' || ch == '\n')
        {
            ++cnt;
            if (cnt == 1)
                obj[0] -= 'a', obj[0] += 'A';
            for (auto x:obj) cout<<x;
            cout<<' ';
            for (auto x:sub) cout<<x;
            cout<<' ';
            for (auto x:ver) cout<<x;
            cout<<ch;
            obj.clear();
            sub.clear();
            ver.clear();
            ok = false;
        }
        else if (ch == '{')
        {
            ok = true;
            while(1)
            {
                cin.get(ch);
                if (ch == '}') break;
                ch = tolower(ch);
                obj.push_back(ch);
            }
        }
        else if (ch == '[')
        {
            ok = true;
            while(1)
            {
                cin.get(ch);
                if (ch == ']') break;
                ch = tolower(ch);
                ver.push_back(ch);
            }
        }
        else if (ch == '(')
        {
            ok = true;
            while(1)
            {
                cin.get(ch);
                if (ch == ')') break;
                ch = tolower(ch);
                sub.push_back(ch);
            }
        }
        else if (!ok)
            cout<<ch;
    }
    return 0;
}
