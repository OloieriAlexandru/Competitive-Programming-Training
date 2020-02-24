#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, b, d[10][3], nr;
void desc(int b){
    memset(d,0,sizeof(d));
    nr = 0;
    for (int i=2;b>1;++i){
        if (b%i){
            continue;
        }
        d[nr][0] = i;
        d[nr][1] = 0;
        while (!(b%i)){
            ++d[nr][1];
            b/=i;
        }
        ++nr;
    }
}
int cif(){
    int p = 1, aux;
    for (int j=0;j<nr;++j){
        d[j][2] = 0;
    }
    for (int i=1;i<=n;++i){
        aux = i;
        for (int j=0;j<nr;++j){
            while (!(aux%d[j][0])){
                ++d[j][2];
                aux /= d[j][0];
            }
        }
        p = (p*aux)%b;
    }
    return p;
}
int computeMinimum(){
    int minn = d[0][2]/d[0][1];
    for (int i=1;i<nr;++i){
        if (d[i][2]/d[i][1]<minn){
            minn=d[i][2]/d[i][1];
        }
    }
    return minn;
}
int compute(){
    int p = cif();
    int minn = computeMinimum();
    for (int i=0;i<nr;++i){
        for (int j=0;j<d[i][2]-d[i][1]*minn;++j){
            p = (p*d[i][0])%b;
        }
    }
    return p;
}
char ans(){
    int res = compute();
    if (res < 10){
        return (char)(res + '0');
    } else {
        return (char)(res-10 + 'A');
    }
}
int main()
{
    freopen("fact.in","r",stdin);
    freopen("fact.out","w",stdout);
    for (int i=1;i<=5;++i){
        cin>>n>>b;
        desc(b);
        cout<<ans()<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
