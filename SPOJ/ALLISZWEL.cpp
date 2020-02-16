#include <bits/stdc++.h>
#define nmax 105
using namespace std;

int n, m;
int dl[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};
const char* req = "ALLIZZWELL";
char mat[nmax][nmax];
bool ok, uz[nmax][nmax];

bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}

void bkt(int i, int j, int poz){
    if (ok){
        return;
    }
    if (poz == 10){
        ok = true;
        return;
    }
    uz[i][j] = true;
    for (int k=0;k<8;++k){
        if (!interior(i+dl[k],j+dc[k])){
            continue;
        }
        if (mat[i+dl[k]][j+dc[k]] == req[poz] && !uz[i+dl[k]][j+dc[k]]){
            bkt(i+dl[k],j+dc[k],poz+1);
        }
        if (ok){
            return;
        }
    }
    uz[i][j] = false;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cin>>mat[i][j];
                uz[i][j]=false;
            }
        }
        ok = false;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (mat[i][j] == req[0]){
                    bkt(i,j,1);
                }
                if (ok){
                    break;
                }
            }
            if (ok){
                break;
            }
        }
        if (ok){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
