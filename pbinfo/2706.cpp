#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, k, ans, sol[nmax], vec[nmax][nmax];
bool a[nmax][nmax];
void gen(int act){
    ans = max(ans, act-1);
    if (act == k+1){
        return;
    }
    for (int i=1;i<=vec[sol[act-1]][0];++i){
        int j = 1;
        for (;j<act;++j){
            if (!a[vec[sol[act-1]][i]][sol[j]]){
                break;
            }
        }
        if (j < act){
            continue;
        }
        sol[act] = vec[sol[act-1]][i];
        gen(act+1);
    }
}
int main()
{
    freopen("serbare2.in","r",stdin);
    freopen("serbare2.out","w",stdout);
    scanf("%d %d",&n,&k);
    vec[0][0] = n;
    for (int i=1;i<=n;++i){
        vec[0][i] = i;
        for (int j=1;j<=n;++j){
            int r;
            scanf("%d",&r);
            if (r){
                a[i][j] = true;
            } else {
                a[i][j] = false;
            }
            if (j > i && r){
                vec[i][++vec[i][0]] = j;
            }
        }
    }
    gen(1);
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
