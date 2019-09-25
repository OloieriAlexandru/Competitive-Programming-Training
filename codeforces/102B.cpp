#include <bits/stdc++.h>
#define lld long long
using namespace std;
char ch;
lld sum;
int ans, cnt;
lld sumOfDigits(lld x)
{
    if (x <= 9) return x;
    return x % 10 + sumOfDigits(x/10);
}
int main()
{
    while (cin>>ch)
        sum += (ch - '0'), ++cnt;
    if (cnt == 1)
    {
        cout<<"0\n";
        return 0;
    }
    while (true)
    {
        ++ans;
        if (sum <= 9)
            break;
        sum = sumOfDigits(sum);
    }
    cout<<ans<<'\n';
    return 0;
}
