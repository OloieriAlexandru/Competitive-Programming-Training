#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    int n, x, a, b;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>a>>b;
        if (a > b)
            swap (a, b);
        int tor=min(x,a-1);
        a-=tor;
        x-=tor;
        int tol=min(x,n-b);
        b+=tol;
        cout<<b-a<<'\n';
    }
    return 0;
}
