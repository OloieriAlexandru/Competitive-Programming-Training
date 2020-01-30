#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        vector<string>v;
        int n, ans=0;
        cin>>n;
        set<string>st;
        unordered_map<string,int>mp;
        for (int i=1;i<=n;++i){
            cin>>s;
            st.insert(s);
            ++mp[s];
            v.push_back(s);
        }
        for (int i=0;i<n;++i){
            if (mp[v[i]] <= 1){
                continue;
            }
            --mp[v[i]];
            for (int j=1;j<=10;++j){
                ++v[i][0];
                if (v[i][0]>'9'){
                    v[i][0]='0';
                }
                if (!st.count(v[i])){
                    break;
                }
            }
            ++mp[v[i]];
            st.insert(v[i]);
            ++ans;
        }
        cout<<ans<<'\n';
        for (auto x:v){
            cout<<x<<'\n';
        }
    }
    return 0;
}
