#include <bits/stdc++.h>
#define nmax 50
using namespace std;
int n, fv[26];
string s, t;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        cin>>s>>t;
        memset(fv,0,sizeof(fv));
        for (auto x:s){
            ++fv[x-'a'];
        }
        for (auto x:t){
            ++fv[x-'a'];
        }
        bool ok=true;
        for (int i=0;i<26;++i){
            if (fv[i]%2){
                ok=false;
                break;
            }
        }
        if (!ok){
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        vector<pair<int,int>>ans;
        for (int i=0;i<s.size();++i){
            if (s[i]==t[i]){
                continue;
            }
            int j;
            bool found = false;
            for (j=i+1;j<s.size();++j){
                if (s[j]==s[i]){
                    found=true;
                    break;
                }
            }
            if (found){
                swap(s[j], t[i]);
                ans.push_back(make_pair(j,i));
                continue;
            }
            for (j=i+1;j<t.size();++j){
                if (t[j]==s[i]){
                    break;
                }
            }
            swap(s[j],t[j]);
            ans.push_back(make_pair(j,j));
            swap(s[j],t[i]);
            ans.push_back(make_pair(j,i));
        }

        cout<<ans.size()<<'\n';
        for (auto x:ans){
            cout<<(x.first+1)<<' '<<(x.second+1)<<'\n';
        }
    }
    return 0;
}
