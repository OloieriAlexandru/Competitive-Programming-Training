#include <bits/stdc++.h>
using namespace std;
int zeros, n;
bool ansZero = false;
string act, frs;
int nrcdz(string &s)
{
    int ret = 0;
    for (auto x:s)
    {
        if (x == '1') ++ret;
        else if (x > '1') ret += 2;
    }
    return ret;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>act;
        if (act.size() == 1 && act[0] == '0')
            ansZero = true;
        else
        {
            if (nrcdz(act) > 1)
                frs = act;
            else
                zeros += (act.size() - 1);
        }
    }
    if (ansZero)
        cout<<"0\n";
    else
    {
        cout<<frs;
        for (int i=0; i<zeros; ++i)
            cout<<'0';
        cout<<'\n';
    }
    return 0;
}
