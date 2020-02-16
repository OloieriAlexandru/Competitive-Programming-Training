#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, m, xs, ys, xf, yf;
int a[nmax][nmax], em[nmax][nmax];
bool visited[nmax][nmax];

int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}

pair<int,int> q[nmax*nmax];
void lee(int l, int c) {
		a[l][c] = 0; // distanta pana la punctul de start e 0
		visited[l][c] = true;
		int fr = 0, ls = 0;
		q[fr].first = l, q[fr].second = c;
		pair<int,int>act;
		int i, j;
		while (fr <= ls) {
            i = q[fr].first, j = q[fr++].second;
			for (int k=0;k<4;++k) {
                if (!interior(i+dl[k],j+dc[k])) continue;
				if (visited[i+dl[k]][j+dc[k]]) continue;
				if (em[i+dl[k]][j+dc[k]]) continue;
				visited[i+dl[k]][j+dc[k]] = true;
				a[i+dl[k]][j+dc[k]] = a[i][j] + 1;
                q[++ls].first = i+dl[k], q[ls].second = j+dc[k];
			}
		}
	}

int main()
{
    freopen("roboti.in","r",stdin);
    freopen("roboti.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",&em[i][j]);
        }
    }
    scanf("%d %d",&xs,&ys);
    scanf("%d %d",&xf,&yf);
    lee(xs, ys);
    if (!visited[xf][yf]){
        printf("-1\n");
    } else {
        printf("%d\n", a[xf][yf]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
