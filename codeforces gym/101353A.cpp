#include <iostream>
#define MAX 100004
using namespace std;
long long int t,n,m;
long long int S,x;
int maxi;
int main(){
    int i,j;
    cin>>t;
    for(i=0;i<t;++i){
        cin>>n>>m;
        S=x=maxi=0;
        for(j=0;j<n;++j){
            cin>>x;
            if(x%m==0)continue;
            S+=(m-(x%m));
        }
        /*if(maxi%m==0)maxi/=m;
        else maxi=maxi/m+1;
        m=m*n*maxi;
        if(S>m)cout<<S-m<<'\n';
        else cout<<S<<'\n';*/
        cout<<S<<'\n';
    }
   return 0;
}
