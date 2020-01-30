#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s, t;
        int n, k;
        cin>>n>>k;
        cin>>s;
        for (int i=1;i<=k-1;++i){
            t += "()";
        }
        int rm = (n - 2 * (k-1))/2;
        for (int i=1;i<=rm;++i){
            t.push_back('(');
        }
        while (t.size()<n){
            t.push_back(')');
        }
        //cout<<s<<'\n';
        //cout<<t<<'\n';
        vector<pair<int,int>>ans;
        for (int i=0;i<s.size();++i){
            if (s[i] == t[i]){
                continue;
            }
            int st = i, dr;
            for (int j=i+1;j<n;++j){
                if (s[j]==t[i]){
                    dr = j;
                    break;
                }
            }
            ans.push_back(make_pair(st,dr));
            while(st<dr){
                swap(s[st],s[dr]);
                ++st,--dr;
            }
        }
        cout<<ans.size()<<'\n';
        for (auto x:ans){
            cout<<x.first+1<<' '<<x.second+1<<'\n';
        }
    }
    return 0;
}
