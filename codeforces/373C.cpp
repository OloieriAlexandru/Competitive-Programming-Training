#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n, x;
vector<int>arr;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        arr.pb(x);
    }
    sort(arr.begin(),arr.end());
    int n2=n/2,ans=n,curr=n2;
    for (int i=0; i<n2; ++i)
    {
        while (true) {
            if (arr[i]*2<=arr[curr]) {
                ++curr;
                --ans;
                break;
            }
            else {
                ++curr;
            }
            if (curr==n){
                break;
            }
        }
        if (curr==n){
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
