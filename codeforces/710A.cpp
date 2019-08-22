#include<bits/stdc++.h>
#define nmax 8
using namespace std;
int dl[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
bool interior(int i, int j)
{
    return i>=1&&i<=8&&j>=1&&j<=8;
}
char ch;
int x, y, ans;
int main()
{
    cin>>ch>>x;
    y = ch - 'a' + 1;
    for (int k=0;k<8;++k)
        if (interior(x+dl[k], y+dc[k])) ++ans;
    cout<<ans<<'\n';
    return 0;
}
