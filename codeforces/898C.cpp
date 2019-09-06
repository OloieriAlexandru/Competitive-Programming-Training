#include <bits/stdc++.h>
using namespace std;
int n, nr;
string name, pn;
map<string,set<string>>cont;
vector<pair<string,vector<string>>>ans;
bool pref(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int ln1 = a.size();
    for (int i=0; i<ln1; ++i)
        if (a[i] != b[i]) return false;
    return true;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>name>>nr;
        for (int j=1; j<=nr; ++j)
        {
            cin>>pn;
            cont[name].insert(pn);
        }
    }
    for (auto x:cont)
    {
        vector<string>act, nums;
        for (auto y:x.second)
            nums.push_back(y);
        sort(nums.begin(), nums.end(), [](string a, string b)
        {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });
        for (int i=0; i<nums.size(); ++i)
        {
            bool ok = true;
            for (int j=i+1; j<nums.size(); ++j)
                if (pref(nums[i], nums[j]))
                {
                    ok = false;
                    break;
                }
            if (ok) act.push_back(nums[i]);
        }
        ans.push_back(make_pair(x.first, act));
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
    {
        cout<<x.first<<' '<<x.second.size()<<' ';
        for (auto y:x.second)
            cout<<y<<' ';
        cout<<'\n';
    }
    return 0;
}
