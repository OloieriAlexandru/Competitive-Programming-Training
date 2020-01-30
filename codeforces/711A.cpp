#include <bits/stdc++.h>
using namespace std;

int main()
{
    #define pb push_back
    bool ok = false;
    int n;
    string s;
    vector<string>v;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (ok){
            v.pb(s);
            continue;
        }
        if (s[0] == s[1] || s[3] == s[4]){
            if (!ok && s[0] == s[1] && s[0] == 'O'){
                s[0] = s[1] = '+';
                ok = true;
            }
            if (!ok && s[3] == s[4] && s[3] == 'O'){
                s[3] = s[4] = '+';
                ok = true;
            }
        }
        v.pb(s);
    }
    if (!ok){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (auto x:v){
        cout<<x<<'\n';
    }
    return 0;
}
