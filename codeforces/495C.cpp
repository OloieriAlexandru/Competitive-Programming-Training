#include <bits/stdc++.h>
using namespace std;
int main()
{
    int balance = 0, open = 0, closed = 0, h = 0, lp;
    string s;
    cin>>s;
    int poz = 0;
    for (auto &x:s)
    {
        if (x == '(') {
            ++open;
        }
        else if (x == ')') {
            ++closed;
        }
        else {
            ++h;
            x=')';
            lp=poz;
        }
        ++poz;
    }
    for (int i=0; i<s.size(); ++i)
    {
        if (s[i]=='(') {
            ++balance;
        }
        else {
            --balance;
        }
        if (balance < 0) {
            cout<<"-1\n";
            return 0;
        }
    }
    if (open < closed + h){
        cout<<"-1\n";
        return 0;
    }
    int ladd = open - (closed + h) + 1;
    balance = 0;
    for (int i=0;i<s.size();++i){
        if (i == lp){
            balance -= ladd;
        } else {
            if (s[i] == '('){
                ++balance;
            } else {
                --balance;
            }
        }
        if (balance < 0){
            cout<<"-1\n";
            return 0;
        }
    }
    if (balance != 0){
        cout<<"-1\n";
    }
    for (int i=1;i<h;++i){
        cout<<1<<'\n';
    }
    cout<<ladd<<'\n';
    return 0;
}
