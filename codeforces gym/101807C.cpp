#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        if (x % 2 == 1 && x != 1){
            cout<<"Yes\n";
            continue;
        }
        while (x % 2 == 0){
            x/=2;
        }
        if (x == 1){
            cout<<"No\n";
        } else {
            cout<<"Yes\n";
        }
    }
    return 0;
}
