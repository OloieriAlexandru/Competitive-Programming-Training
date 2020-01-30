#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;
    set<char>st;
    for (int i=1;i<=k;++i){
        char ch;
        cin>>ch;
        st.insert(ch);
    }
    long long ans = 0;
    for (int i=0;i<n;++i){
        if (!st.count(s[i])){
            continue;
        }
        int cnt = 1;
        while (i < n - 1 && st.count(s[i+1])){
            ++i, ++cnt;
        }
        ans += 1LL * cnt * (cnt+1) / 2;
    }
    cout<<ans<<'\n';
    return 0;
}
