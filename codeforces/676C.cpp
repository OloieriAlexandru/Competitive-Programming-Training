#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int cnt1[nmax], cnt2[nmax];
int n, k;
bool ok(int cnt){
    for (int i=0;i<=n-cnt;++i){
        int v1 = cnt1[i+cnt-1] - (i==0?0:cnt1[i-1]);
        int v2 = cnt2[i+cnt-1] - (i==0?0:cnt2[i-1]);
        if (v1 <= k || v2 <= k){
            return true;
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>n>>k;
    cin>>s;
    if (s[0]=='a'){
        ++cnt1[0];
    } else {
        ++cnt2[0];
    }
    for (int i=1;i<n;++i){
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        if (s[i]=='a'){
            ++cnt1[i];
        } else {
            ++cnt2[i];
        }
    }
    int st = 1, dr = n, ans;
    while(st<=dr){
        int m=(st+dr)/2;
        if (ok(m)){
            ans=m,st=m+1;
        } else {
            dr=m-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
