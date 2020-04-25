#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax
#define inf
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n){
        if (n % 10 == 7){
            cout<<"Yes\n";
            return 0;
        }
        n/=10;
    }
    cout<<"No\n";
    return 0;
}
