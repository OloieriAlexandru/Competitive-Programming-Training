#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        if ((a+b)%3){
            cout<<"NO\n";
            continue;
        }
        if (a > b){
            swap(a,b);
        }
        if (a*2<b){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}
