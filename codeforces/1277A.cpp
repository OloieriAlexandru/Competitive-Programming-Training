#include <bits/stdc++.h>
using namespace std;
vector<int>all;
void gen(){
    for (int i=1;i<=9;++i){
        for (int j=1;j<=9;++j){
            int act = 0;
            for (int k=0;k<i;++k){
                act = act * 10 + j;
            }
            all.push_back(act);
        }
    }
}
int cnt(int n){
    int res = 0;
    for (auto x:all){
        if (x <= n){
            ++res;
        }
    }
    return res;
}
int main()
{
    gen();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<cnt(n)<<'\n';
    }
    return 0;
}
