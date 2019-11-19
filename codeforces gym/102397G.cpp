#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, k, a[nmax], b[nmax];
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
    }
    map<int,int>mp;
    int cnt1 = 0, cnt2 = 0;
    for (int i=1;i<=n;++i){
        int need = k - a[i];
        cnt1+=mp[need];
        ++mp[a[i]];
    }
    mp.clear();
    for (int i=1;i<=n;++i){
        int need = k - b[i];
        cnt2+=mp[need];
        ++mp[b[i]];
    }
    if (cnt1>cnt2){
        cout<<"Mahmoud\n";
    }
    else if (cnt1<cnt2){
        cout<<"Bashar\n";
    }
    else {
        cout<<"Draw\n";
    }
    return 0;
}
