#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax
#define inf
using namespace std;
char ch;
string s;
string decod(string s){
    if (s.size() == 1){
        return s;
    }
    string s1, s2;
    for (int i=0;i<s.size();++i){
        if (i%2){
            s2.push_back(s[i]);
        } else {
            s1.push_back(s[i]);
        }
    }
    return decod(s1) + decod(s2);
}
int main()
{
    freopen("spioni.in","r",stdin);
    freopen("spioni.out","w",stdout);
    cin>>ch;
    cin>>s;
    if (ch == 'C'){
        cout<<decod(s)<<'\n';
    } else {
        cout<<decod(s)<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
