#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax 4005
#define inf
using namespace std;
int a[3][nmax];
int get(char c){
    if (c == 'R'){
        return 0;
    }
    if (c == 'G'){
        return 1;
    }
    return 2;
}
int oth(int a, int b){
    if (a > b){
        swap(a, b);
    }
    if (a == 0){
        if (b == 1){
            return 2;
        }
        return 1;
    }
    if (a == 1){
        if (b == 0){
            return 2;
        }
        return 0;
    }
    if (b == 1){
        return 0;
    }
    return 1;
}
char chh(int x){
    if (x == 0){
        return 'R';
    }
    if (x == 1){
        return 'G';
    }
    return 'B';
}
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for (int i=n-1;i>=0;--i){
        for (int j=0;j<3;++j){
            a[j][i] = a[j][i+1];
        }
        int ind = get(s[i]);
        ++a[ind][i];
    }
    long long ans = 0;
    for (int i=0;i<n;++i){
        int ind1 = get(s[i]);
        for (int j=i+1;j<n-1;++j){
            int ind2 = get(s[j]);
            if (ind1 == ind2){
                continue;
            }
            int ot = oth(ind1, ind2);
            int add = a[ot][j+1];
            int diff = j - i;
            if (j + diff < n){
                if (chh(ot) == s[j+diff]){
                    --add;
                }
            }
            ans += add;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
