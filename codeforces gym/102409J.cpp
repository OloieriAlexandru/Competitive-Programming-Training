#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
#define inf 199999999999999999LL
using namespace std;
int n;
lld l, a[nmax], v, s[nmax];
lld v1, v2, v3, v4, ans = inf, minn, maxx;
void cb(int st, int dr, lld &v1, lld &v2){
    int ddd = dr;
    lld sub=s[st-1];
    lld val1, val2, minnn=inf, diff;
    int m;
    while (st<=dr){
        m=(st+dr)/2;
        val1=s[m]-sub;
        val2=s[ddd]-s[m];
        diff=abs(val1-val2);
        if (diff<minnn){
            minnn=diff;
            v1=val1;
            v2=val2;
        }
        if (val1==val2){
            return;
        }
        if (val1<val2){
            st=m+1;
        } else {
            dr=m-1;
        }
    }
}
int main()
{
    cin>>n>>l;
    for (int i=2;i<=n;++i){
        cin>>a[i];
    }
    a[n+1]=l;
    for (int i=1;i<=n;++i){
        v=a[i+1]-a[i];
        s[i]=s[i-1]+v;
    }
    for (int i=2;i<=n-2;++i){
        cb(1,i,v1,v2);
        cb(i+1,n,v3,v4);
        minn=v1,maxx=v1;
        minn=min(minn,v2);maxx=max(maxx,v2);
        minn=min(minn,v3);maxx=max(maxx,v3);
        minn=min(minn,v4);maxx=max(maxx,v4);
        ans=min(ans,maxx-minn);
    }
    cout<<ans<<'\n';
    return 0;
}
