#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int>v;
    for (int i=0;i<n;++i){
        int cnt = 1;
        while (i < n-1 && s[i] == s[i+1]){
            ++i, ++cnt;
        }
        v.push_back(cnt);
    }
    long long ans = 1LL * n * (n-1) / 2;

    for (int i=0;i<v.size()-1;++i){
        ans -= v[i];
    }
    for (int i=v.size()-1;i>0;--i){
        ans -= (v[i]-1);
    }

    cout<<ans<<'\n';
    return 0;
}
