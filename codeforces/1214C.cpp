#include <bits/stdc++.h>
#define inf 999999999
using namespace std;
string s;
bool ok = false;
int n,op, clos, minn = inf, act = 0;
int main()
{
    cin>>n>>s;
    for (int i=0; i<n; ++i)
    {
        if (s[i] == '(')
            ++op, ++act;
        else
            ++clos, --act;
        minn = min(minn, act);
    }
    if (minn == -1 || act == 1 || (act == 0 && minn == 0))
        ok = true;
    if (op != clos)
        ok = false;
    if (ok)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
