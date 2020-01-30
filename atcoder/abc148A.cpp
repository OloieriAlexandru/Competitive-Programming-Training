#include <bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define nmax
#define pii pair<int,int>
#define inf
using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    if (a > b) swap(a,b);
    if (a == 1 && b == 2){
        cout<<"3\n";
    } else if (a == 1 && b == 3){
        cout<<"2\n";
    } else{
        cout<<"1\n";
    }
	return 0;
}
