#include <bits/stdc++.h>
using namespace std;
string s[3];
int ln, n, num;
vector<int>poz;
vector<char>ans, good;
void dfs(int pz)
{
    if (pz == n)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i=0; i<n; ++i)
        {
            if (s[0][poz[i]] != ans[i])
                ++cnt1;
            if (s[1][poz[i]] != ans[i])
                ++cnt2;
            if (s[2][poz[i]] != ans[i])
                ++cnt3;
        }
        if (cnt1 <= 1 && cnt2 <= 1 && cnt3 <= 1)
        {
            ++num;
            good = ans;
        }
        return;
    }

    for (char ch='a'; ch<='z'; ++ch)
    {
        ans[pz] = ch;
        dfs(pz+1);
    }
}
int main()
{
    for (int i=0; i<3; ++i)
        cin>>s[i];
    ln = s[0].size();
    for (int i=0; i<ln; ++i)
    {
        if (s[0][i] != s[1][i] || s[0][i] != s[2][i] || s[1][i] != s[2][i])
            poz.push_back(i);
    }
    if (poz.size() >= 4)
        cout<<"Impossible\n";
    else if (poz.size() == 0 || poz.size() == 1)
        cout<<"Ambiguous\n";
    else
    {
        ans.resize(poz.size());
        n = poz.size();
        dfs(0);
        if (num == 1)
        {
            for (int i=0;i<n;++i)
                s[0][poz[i]] = good[i];
            cout<<s[0]<<'\n';
        }
        else if (num > 1)
            cout<<"Ambiguous\n";
        else
            cout<<"Impossible\n";
    }
    return 0;
}
