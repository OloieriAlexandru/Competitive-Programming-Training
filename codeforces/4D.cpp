#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define nmax 5005
#define inf 999999999
using namespace std;
int n, w, h, x, y;
int dp1[nmax], dp2[nmax];
vector<int>anss;
vector<pair<pii,int>>v;
bool cmp(const pair<pii,int>& a, const pair<pii,int>& b){
    if (a.first == b.first){
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}
bool better(int ii, int jj){
    return v[ii].first.first > v[jj].first.first && v[ii].first.second > v[jj].first.second;
}
int main()
{
    scanf("%d %d %d",&n,&w,&h);
    v.push_back(mp(mp(w,h),0));
    for (int i=1;i<=n;++i){
        scanf("%d %d",&x,&y);
        v.pb(mp(mp(x,y),i));
    }
    sort(v.begin()+1, v.end(), cmp);
    dp1[0]=0;
    for (int i=1;i<=n;++i){
        dp1[i]=-inf;
    }
    for (int i=0;i<=n;++i){
        if (dp1[i]==-inf) continue;
        for (int j=1;j<=n;++j){
            if (better(j, i)){
                if (dp1[j] < dp1[i]+1){
                    dp2[j]=i;
                    dp1[j]=dp1[i]+1;
                }
            }
        }
    }
    int ans=0, pos;
    for (int i=1;i<=n;++i){
        if (dp1[i]>ans){
            ans=dp1[i];
            pos=i;
        }
    }
    cout<<ans<<'\n';
    if (!ans){
        return 0;
    }
    while (pos){
        anss.push_back(v[pos].second);
        pos=dp2[pos];
    }
    reverse(anss.begin(), anss.end());
    for (auto x:anss){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
