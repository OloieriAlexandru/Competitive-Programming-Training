#include <bits/stdc++.h>
using namespace std;
char skip13(char ch){
    int nch=(int)ch+13;
    if (nch>'z'){
        int d=nch-'z';
        ch='a'+d-1;
    } else ch=nch;
    return ch;
}
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        reverse(s.begin(),s.end());
        string af;
        for (auto x:s){
            if (x>='A'&&x<='Z'){
                x=x-'A'+'a';
                x=skip13(x);
            } else {
                x=skip13(x);
                x=x-'a'+'A';
            }
            af.push_back(x);
        }
        cout<<af<<'\n';
    }
    return 0;
}
