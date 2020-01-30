#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l = 0, r = 0, u = 0, d = 0;
        for (auto x:s){
            if (x == 'L'){
                ++l;
            } else if (x == 'R'){
                ++r;
            } else if (x == 'U'){
                ++u;
            } else {
                ++d;
            }
        }
        string ans;
        int m1 = min(l,r);
        int m2 = min(u,d);
        if (!m1 && m2){
            m2 = 1;
        } else if (!m2 && m1){
            m1 = 1;
        }
        for (int i=1;i<=m1;++i){
            ans.push_back('L');
        }
        for (int i=1;i<=m2;++i){
            ans.push_back('D');
        }
        for (int i=1;i<=m1;++i){
            ans.push_back('R');
        }
        for (int i=1;i<=m2;++i){
            ans.push_back('U');
        }
        cout<<ans.size()<<'\n'<<ans<<'\n';
    }
    return 0;
}
