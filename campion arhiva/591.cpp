#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 155
#define nmax2 25555
using namespace std;
int n, m, k, nr, l, c, ans, ii, jj, nl, nc;
short a[nmax][nmax], num[nmax][nmax];
bool visited[nmax][nmax], haveKey[nmax2], checked[nmax][nmax];
vector<pii> notEntered[nmax2];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}
void filll(int l, int c){
    queue<pii>q;
    pii act;
    int i, j;
    visited[l][c] = true;
    haveKey[num[l][c]] = true;
    q.push(mp(l, c));
    while(!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        for (unsigned int t=0;t<notEntered[num[i][j]].size();++t){
            nl = notEntered[num[i][j]][t].first;
            nc = notEntered[num[i][j]][t].second;
            haveKey[num[nl][nc]] = true;
            if (!visited[nl][nc]){
                visited[nl][nc] = true;
                q.push(mp(nl,nc));
            }
        }
        for (int k=0;k<4;++k){
            ii = i+dl[k];
            jj = j+dc[k];
            if (!interior(ii,jj)){
                continue;
            }
            if (haveKey[a[ii][jj]]){
                haveKey[num[ii][jj]] = true;
                if (!visited[ii][jj]){
                    q.push(mp(ii,jj));
                    visited[ii][jj] = true;
                }
            } else {
                if (!checked[ii][jj]){
                    checked[ii][jj] = true;
                    notEntered[a[ii][jj]].push_back(mp(ii,jj));
                }
            }
        }
    }
}
int main()
{
    freopen("castel.in","r",stdin);
    freopen("castel.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            num[i][j] = ++nr;
            if (nr == k){
                l = i, c = j;
            }
        }
    }
    filll(l, c);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (visited[i][j]){
                ++ans;
            }
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
