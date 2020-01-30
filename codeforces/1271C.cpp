#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int ans, ansx, ansy, n, x, y, cx, cy;
vector<pii>v;
int cnt(int currx, int curry){
    int res = 0;
    int casee;
    if (currx == x){
        if (curry < y){
            casee = 1;
        } else {
            casee = 2;
        }
    } else {
        if (currx < x){
            casee = 3;
        } else {
            casee = 4;
        }
    }
    for (auto el:v){
        if (casee == 1){
            if (el.second < y){
                ++res;
            }
        }
        else if (casee == 2){
            if (el.second > y){
                ++res;
            }
        }
        else if (casee == 3){
            if (el.first < x){
                ++res;
            }
        }
        else{
            if (el.first > x){
                ++res;
            }
        }
    }
    return res;
}
int main()
{
    cin>>n>>x>>y;
    for (int i=1;i<=n;++i){
        cin>>cx>>cy;
        v.pb(mp(cx,cy));
    }
    int dl1[] = {-1,0,1,0};
    int dc1[] = {0,1,0,-1};
    for (int i1 = 0; i1 < 4; ++i1){
            int checkx = x + dl1[i1];
            int checky = y + dc1[i1];
            int co = cnt(checkx, checky);
            if (co > ans){
                ans = co, ansx = checkx, ansy = checky;
            }
    }
    cout<<ans<<'\n';
    cout<<ansx<<' '<<ansy<<'\n';
    return 0;
}
