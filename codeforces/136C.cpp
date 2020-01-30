#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>ans;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        int x;
        cin>>x;
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    int l = ans[n-1];
    ans.pop_back();
    if (l == 1){
        ans.push_back(2);
    } else {
        ans.push_back(1);
    }
    sort(ans.begin(),ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
