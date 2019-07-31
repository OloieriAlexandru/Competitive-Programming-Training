#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, x;
long long ans = 0;
vector<int>arr;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        arr.push_back(abs(x));
    }
    sort(arr.begin(), arr.end());
    int r = 1;
    for (int i=0;i<arr.size();++i)
    {
        while (r < arr.size() && arr[r]<=2*arr[i]) ++r;
        ans += (r-1-i);
    }
    cout<<ans<<'\n';
    return 0;
}
