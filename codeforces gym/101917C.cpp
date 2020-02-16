#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, v;
    string s;
    cin>>t>>v;
    v %= 26;
    cin.get();
    while(t--){
        getline(cin,s);
        for (int i=0;i<s.size();++i){
            if (s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - v;
                if (s[i] < 'a'){
                    int diff = 'a' - s[i];
                    --diff;
                    s[i] = 'z' - diff;
                }
            } else if (s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - v;
                if (s[i] < 'A'){
                    int diff = 'A' - s[i];
                    --diff;
                    s[i] = 'Z' - diff;
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
