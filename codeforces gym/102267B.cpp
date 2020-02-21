#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define nmax 10000005
#define inf
using namespace std;
bool ciur[nmax];
void doCiur(){
    ciur[0]=ciur[1]=true;
    for (long long i=2;i*i<=10000000;++i){
        if (ciur[i]){
            continue;
        }
        for (long long j=i*i;j<=10000000;j+=i){
            ciur[j]=true;
        }
    }
}
int main(){
    int n;
    cin>>n;
    doCiur();
    for (int i=2;i<=n;++i){
        if (!ciur[i] && !ciur[n-i]){
            cout<<i<<' '<<n-i<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
	return 0;
}
