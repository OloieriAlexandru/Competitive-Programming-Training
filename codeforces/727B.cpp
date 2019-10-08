#include <bits/stdc++.h>
using namespace std;
string s;
int sum, sumcents, ln;
int main()
{
    cin>>s;
    ln = s.size();
    for (int i=0; i<ln; ++i)
    {
        while (i < ln-1 && s[i] >= 'a' && s[i] <= 'z')
            ++i;
        int j = i;
        while (j < ln && (s[j] == '.' || (s[j] >= '0' && s[j] <= '9')))
            ++j;
        int cj = j-1;
        if (cj >= 2)
        {
            if (s[cj-2] == '.')
            {
                sumcents += (s[cj]-'0' + (s[cj-1]-'0')*10);
                cj = cj - 3;
            }
        }
        int toAdd = 0, pw = 1;
        while (cj >= i)
        {
            if (s[cj] == '.')
            {
                --cj;
                continue;
            }
            toAdd = toAdd + pw*(s[cj] - '0');
            --cj, pw*=10;
        }
        sum += toAdd;
        i = j - 1;
    }
    sum += sumcents/100;
    sumcents = sumcents%100;
    string ans;
    if (!sum)
    {
        ans.push_back('0');
        //ans.push_back('.');
    }
    else
    {
        int cnt = 0;
        while (sum)
        {
            ans.push_back(sum%10+'0');
            ++cnt;
            if (cnt == 3)
            {
                ans.push_back('.');
            }
            cnt %= 3;
            sum /= 10;
        }
        if (ans.back()=='.')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        //ans.push_back('.');
    }
    cout<<ans;
    if (sumcents)
    {
        cout<<'.';
        if (sumcents < 10)
            cout<<'0'<<sumcents<<'\n';
        else
            cout<<sumcents<<'\n';
    }
    return 0;
}
