#include <iostream>
#include <cstring>
#define LMAX 5005
#define lld long long
#define pb push_back
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
#define ud unsigned
#define read1(x) scanf("%d",&x);
#define read2(x, y) scanf("%d %d",&x,&y);
using namespace std;

char s[LMAX];
int lg;
lld dp[LMAX];

lld ans()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i=1; i<lg; ++i)
    {
        if (s[i]!='0')
        {
            dp[i] = dp[i-1];
        }
        if (i>=1 && (s[i]>='0'&&s[i]<='6'&&s[i-1]=='2' || s[i]>='0'&&s[i]<='9'&&s[i-1]=='1'))
        {
            if (i == 1)
            {
                dp[i]++;
            }
            else
            {
                dp[i] += dp[i-2];
            }
        }
    }
    return dp[lg-1];
}

int main()
{
    while (cin>>s)
    {
        lg  = strlen(s);
        if (lg == 1 && s[0] == '0')
        {
            break;
        }
        cout<<ans()<<'\n';
    }
    return 0;
}
