#include <bits/stdc++.h>
using namespace std;
bool ok(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return !(s == t);
}
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    while (len){
        for (int i=0;i+len-1<s.size();++i){
            if (ok(s.substr(i,len))){
                cout<<len<<'\n';
                return 0;
            }
        }
        --len;
    }
    cout<<"0\n";
    return 0;
}
