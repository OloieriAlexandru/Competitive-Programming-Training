#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int t, n, m, k, chk;
char a[nmax][nmax];
int ans[nmax][nmax];
char trans(int x){
    if (x <= 9){
        return x + '0';
    }
    x -= 10;
    if (x < 26){
        return x + 'a';
    }
    x -= 26;
    return x + 'A';
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        chk = 0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cin>>a[i][j];
                if (a[i][j] == 'R'){
                    ++chk;
                }
            }
        }
        int cnt = chk / k;
        int r = chk % k;
        int curr = 0, num = 0;
        for (int i=1;i<=n;++i){
            if (i % 2){
                for (int j=1;j<=m;++j){
                    if (a[i][j] == 'R'){
                        ++num;
                    }
                    ans[i][j] = curr;
                    if (curr < r){
                        if (num >= (cnt + 1) && curr < k-1){
                            ++curr;
                            num = 0;
                        }
                    } else {
                        if (num >= cnt && curr < k-1){
                            ++curr;
                            num = 0;
                        }
                    }
                }
            } else {
                for (int j=m;j>=1;--j){
                    if (a[i][j] == 'R'){
                        ++num;
                    }
                    ans[i][j] = curr;
                    if (curr < r){
                        if (num >= (cnt + 1) && curr < k-1){
                            ++curr;
                            num = 0;
                        }
                    } else {
                        if (num >= cnt && curr < k-1){
                            ++curr;
                            num = 0;
                        }
                    }

                }
            }
        }
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cout<<trans(ans[i][j]);
            }
            cout<<'\n';
        }
    }
    return 0;
}
