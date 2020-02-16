#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 1005
using namespace std;
unsigned short dp[nmax][nmax];
int mars[nmax], n, x, ans, wh;
FILE *fin=fopen("custi.in","r");
FILE *fout=fopen("custi.out","w");
int main()
{
    unsigned short i, j;
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;++i){
        for (j=1;j<=n;++j){
            fscanf(fin,"%d",&x);
            if (x){
                dp[i][j] = dp[i-1][j-1];
                if (dp[i-1][j] < dp[i][j]){
                    dp[i][j] = dp[i-1][j];
                }
                if (dp[i][j-1] < dp[i][j]){
                    dp[i][j] = dp[i][j-1];
                }
                ++dp[i][j];
                ++mars[1];
                --mars[dp[i][j]+1];
            }
        }
    }
    for (i=1;i<=n;++i){
        ans += mars[i];
        fprintf(fout,"%d\n",ans);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
