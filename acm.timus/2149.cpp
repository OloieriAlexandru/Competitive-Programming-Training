#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    vector<int>ori;
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();i+=5){
        if (s[i+2] == '@'){
            ori.push_back(1);
        } else {
            ori.push_back(0);
        }
    }
    cin>>s;
    cin>>s;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    vector<int>v1,v2,v3,v4;
    for (int i=0;i<n;++i){
        if (i < n / 2){
            v1.push_back(0);
            v2.push_back(1);
        } else {
            v1.push_back(1);
            v2.push_back(0);
        }
        v3.push_back(i%2);
        v4.push_back(1-i%2);
    }
    for (int i=0;i<ori.size();++i){
        if (v1[i] != ori[i]){
            ++n1;
        }
        if (v2[i] != ori[i]){
            ++n2;
        }
        if (v3[i] != ori[i]){
            ++n3;
        }
        if (v4[i] != ori[i]){
            ++n4;
        }
    }
    int minn = min(min(n1,n2),min(n3,n4));
    cout<<minn<<'\n';
    return 0;
}
