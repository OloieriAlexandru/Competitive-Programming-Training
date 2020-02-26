#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 22
using namespace std;
int n, a[nmax][nmax], ans;
int dl[] = {0,1};
int dc[] = {1,0};
bool interior(int i, int j){
    return i<=n&&j<=n;
}
int countUp(int i, int j){
    int res = 0;
    for (int k=i+1;k<=n&&a[i][j]==a[k][j];++k){
        ++res;
    }
    return res;
}
int countDown(int i, int j){
    int res = 0;
    for (int k=i-1;k>=1&&a[i][j]==a[k][j];--k){
        ++res;
    }
    return res;
}
int countLeft(int i, int j){
    int res = 0;
    for (int k=j-1;k>=1&&a[i][j]==a[i][k];--k){
        ++res;
    }
    return res;
}
int countRight(int i, int j){
    int res = 0;
    for (int k=j+1;k<=n&&a[i][j]==a[i][k];++k){
        ++res;
    }
    return res;
}
int getScore(int up, int down, int lf, int rg){
    int v = up+down+1;
    int h = lf+rg+1;
    if (v >= 3 && h >= 3){
        return 5+(v+h-6);
    } else if (v >= 3){
        return v-2;
    } else if (h >= 3){
        return h-2;
    }
    return 0;
}
void check(int x1, int y1, int x2, int y2){
    int up1 = countUp(x1, y1), up2 = countUp(x2, y2);
    int down1 = countDown(x1, y1), down2 = countDown(x2, y2);
    int left1 = countLeft(x1, y1), left2 = countLeft(x2, y2);
    int right1 = countRight(x1, y1), right2 = countRight(x2, y2);
    int score1 = getScore(up1, down1, left1, right1);
    int score2 = getScore(up2, down2, left2, right2);
    ans = max(ans, score1+score2);
}
int main()
{
    freopen("tabla.in","r",stdin);
    freopen("tabla.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            for (int k=0;k<2;++k){
                if (!interior(i+dl[k],j+dc[k])){
                    continue;
                }
                swap(a[i][j],a[i+dl[k]][j+dc[k]]);
                check(i, j, i+dl[k], j+dc[k]);
                swap(a[i][j],a[i+dl[k]][j+dc[k]]);
            }
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
