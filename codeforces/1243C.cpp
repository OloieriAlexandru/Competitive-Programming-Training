#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n;
int main()
{
    cin>>n;
    for (lld i=2;i*i<=n;++i){
        if (n % i){
            continue;
        }
        while (n > 1 && n%i==0){
            n/=i;
        }
        if (n==1){
            cout<<i<<'\n';
            return 0;
        } else {
            cout<<1<<'\n';
            return 0;
        }
    }
    if (n > 1){
        cout<<n<<'\n';
        return 0;
    }
    cout<<"1\n";
    return 0;
}
