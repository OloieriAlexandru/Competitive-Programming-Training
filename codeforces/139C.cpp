#include<bits/stdc++.h>

using namespace std;

int n, k;
int main(){
    cin>>n>>k;
    int aaaa = 0;
    unordered_map<string,int>mp;
    for (int i=1;i<=n;++i)
    {
        vector<string>v;
        string str;
        bool ok = true;
        for (int j=1;j<=4;++j)
        {
            cin>>str;
            int poz=-1, cnt = 0;
            string curr;
            for (int j=str.size()-1;j>=0;--j)
            {
                if (strchr("aeiou", str[j]))
                {
                    ++cnt;
                    if (cnt == k)
                    {
                        poz = j;
                        break;
                    }
                }
            }
            if (poz == -1)
                ok = false;
            for (int j=poz;j<str.size();++j)
            {
                curr.push_back(str[j]);
            }
            v.push_back(curr);
        }
        if (!ok)
        {
            cout<<"NO\n";
            return 0;
        }
        if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3])
            {++aaaa; continue;}
        if(v[0] == v[3] && v[1] == v[2])
            ++mp["abba"];
        else
        if (v[0] == v[1] && v[2] == v[3])
            ++mp["aabb"];
        else
        if (v[0] == v[2] && v[1] == v[3])
            ++mp["abab"];
    }
    if (aaaa == n)
    {
        cout<<"aaaa\n";
        return 0;
    }
    if (mp.size() == 1)
    {
        string ans;
        for (auto x:mp)
            ans = x.first;
        cout<<ans<<'\n';
    }
    else
    cout<<"NO\n";
    return 0;
}
