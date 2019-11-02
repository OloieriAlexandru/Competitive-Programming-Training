#include <bits/stdc++.h>
#define inf 999999999
using namespace std;
int ln;
string s;
int main()
{
    cin>>ln;
    cin>>s;
    int open=0,closed=0;
    for (auto x:s){
        if (x == '(') ++open;
        else ++closed;
    }
    if (open!=closed){
        cout<<"0\n1 1\n";
        return 0;
    }
    int ans = -1, v1, v2;
    for (int i=0;i<ln-1;++i){
        for (int j=i;j<ln;++j){
            swap(s[i],s[j]);
            int minn = inf, cnt=0, curr = 0;
            for (auto x:s){
                if (x == '(') ++curr;
                else --curr;
                if (curr < minn) minn = curr, cnt = 1;
                else if (curr == minn) ++cnt;
            }
            if (cnt > ans){
                ans = cnt, v1 = i+1, v2 = j+1;
            }
            swap(s[i],s[j]);
        }
    }
    cout<<ans<<'\n';
    cout<<v1<<' '<<v2<<'\n';
    return 0;
}
