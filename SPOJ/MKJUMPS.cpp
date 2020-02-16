#include <bits/stdc++.h>
#define nmax 15
using namespace std;
int n = 10, m, ans, x, y, act;
int dl[]={-2,-2,-1,-1,1,1,2,2};
int dc[]={-1,1,-2,2,-2,2,-1,1};
bool blocked[nmax][nmax], used[nmax][nmax];
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=n;
}
void bkt(int i, int j){
    used[i][j] = true;
    ++act;
    ans = max(ans, act);
    for (int k=0;k<8;++k){
        if (!interior(i+dl[k],j+dc[k])){
            continue;
        }
        if (blocked[i+dl[k]][j+dc[k]] || used[i+dl[k]][j+dc[k]]){
            continue;
        }
        bkt(i+dl[k],j+dc[k]);
    }
    --act;
    used[i][j] = false;
}
int main()
{
    int t=0;
    while(cin>>m){
        if (!m){
            break;
        }
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                blocked[i][j] = true;
                used[i][j] = false;
            }
        }
        int tot = 0;
        for (int i=1;i<=m;++i){
            cin>>x>>y;
            for (int j=1;j<=y;++j){
                blocked[i][x+j] = false;
                ++tot;
            }
        }
        ans = 0;
        bkt(1,1);
        printf("Case %d, %d square%s can not be reached.\n", ++t, tot-ans, tot-ans == 1?"":"s");
    }
    return 0;
}
