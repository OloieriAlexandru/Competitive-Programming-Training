#include <bits/stdc++.h>
#define nmax 25555
#define nmax2 1005
#define inf 999999999
using namespace std;
ifstream fin("echitabil.in");
ofstream fout("echitabil.out");

int n, sum, a[nmax2], lst[nmax2], maxx, minn, start, diff, sz;
int ans1, ans2;
vector<int> s1, s2;
bool dp[nmax], taken[nmax];

void printVector(const vector<int>& v){
    fout<<v.size()<<'\n';
    sz = v.size();
    for (int i=0;i<sz;++i){
        fout<<v[i]<<' ';
    }
    fout<<'\n';
}

int main()
{
    return 0;
    fin>>n;
    for (int i=1;i<=n;++i){
        fin>>a[i];
        sum += a[i];
    }
    maxx = sum / 2 + 50;
    dp[0] = true;
    for (int i=1;i<=n;++i){
        for (int j=maxx;j>=0;--j){
            if (j - a[i] < 0){
                break;
            }
            if (dp[j] || !dp[j-a[i]]){
                continue;
            }
            dp[j] = true;
            lst[j] = i;
        }
    }
    minn = inf;
    for (int i=maxx;i>=0;--i){
        if (dp[i]){
            diff = abs((sum-i)-i);
            if (diff < minn){
                minn = diff;
                start = i;
            }
        }
    }
    ans1 = start;
    ans2 = sum - ans1;

    while (start){
        s1.push_back(a[lst[start]]);
        taken[lst[start]] = true;
        start = start - a[lst[start]];
    }

    for (int i=1;i<=n;++i){
        if (!taken[i]){
            s2.push_back(a[i]);
        }
    }

    if (ans1 <= ans2){
        fout<<ans1<<' '<<ans2<<'\n';
        printVector(s1);
        printVector(s2);
    } else {
        fout<<ans2<<' '<<ans1<<'\n';
        printVector(s2);
        printVector(s1);
    }
    fin.close();
    fout.close();
    return 0;
}
