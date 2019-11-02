#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string ans;
        int app[26] = {};
        for (int i=0;i<s.size();++i){
            if (i < s.size()-1 && s[i] == s[i+1]){
                ++i;
                continue;
            }
            app[s[i]-'a'] = 1;
        }
        for (int i=0;i<26;++i){
            if (!app[i]) continue;
            cout<<(char)(i+'a');
        }
        cout<<'\n';
    }
    return 0;
}
