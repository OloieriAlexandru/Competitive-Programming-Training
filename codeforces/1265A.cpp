#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool ok = true;
        for (int i=0;i<s.size()-1;++i){
            if (s[i] == s[i+1] && s[i] != '?'){
                ok = false;
                break;
            }
        }
        if (!ok){
            cout<<"-1\n";
            continue;
        }
        for (int i=0;i<s.size();++i){
            if (s[i] != '?'){
                continue;
            }
            if (i == 0 || s[i-1] == 'a'){
                if (i == s.size()-1 || s[i+1] == 'b'){
                    s[i] = 'c';
                } else
                if (i == s.size()-1 || s[i+1] == 'c'){
                    s[i] = 'b';
                } else {
                    s[i] = 'b';
                }
            }
            if (i == 0 || s[i-1] == 'b'){
                if (i == s.size()-1 || s[i+1] == 'a'){
                    s[i] = 'c';
                } else
                if (i == s.size()-1 || s[i+1] == 'c'){
                    s[i] = 'a';
                } else {
                    s[i] = 'a';
                }
            }
            if (i == 0 || s[i-1] == 'c'){
                if (i == s.size()-1 || s[i+1] == 'b'){
                    s[i] = 'a';
                } else
                if (i == s.size()-1 || s[i+1] == 'a'){
                    s[i] = 'b';
                } else {
                    s[i] = 'b';
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
