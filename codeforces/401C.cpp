#include <bits/stdc++.h>
using namespace std;
string ans;
int main()
{
    int n, m;
    cin>>n>>m;
    swap(n, m);
    while (m && n)
    {
        if (n)
        {
            ans.push_back('1');
            --n;
        }
        if (n)
        {
            ans.push_back('1');
            --n;
        }
        if (m)
        {
            ans.push_back('0');
            --m;
        }
    }
    if (ans.back() == '0' && n)
    {
        --n;
        ans.push_back('1');
        if (n)
        {
            --n;
            ans.push_back('1');
        }
    }
    bool ok = false;
    bool atBeginning = false;
    if (m)
    {
        atBeginning = true;
        --m;
    }
    int cm = 0;
    for (int i=0; i<ans.size(); ++i)
    {
        if (ans[i] == '0') continue;
        if (i < ans.size()-1 && ans[i+1] == '1')
            if (cm < m) ++cm;
    }
    if (cm == m)
        ok = true;
    if (!ok || n)
        cout<<"-1\n";
    else
    {
        int cm = 0;
        if (atBeginning)
            cout<<'0';
        for (int i=0; i<ans.size(); ++i)
        {
            if (ans[i] == '0')
            {
                cout<<ans[i];
                continue;
            }
            cout<<'1';
            if (i < ans.size()-1 && ans[i+1] == '1')
            {
                if (cm < m)
                {
                    ++cm;
                    cout<<'0';
                }
            }
        }
    }
    return 0;
}
