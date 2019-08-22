#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a[nmax], n, k;
string s;
int tot;

int main()
{
    cin>>n>>k;
    cin>>s;
    for (int i=0; i<s.size(); ++i)
    {
        a[i] = s[i] - 'a';
        tot += max(25 - a[i],max(a[i],0));
    }
    if (tot < k)
    {
        cout<<"-1\n";
        return 0;
    }
    for (int i=0; i<s.size(); ++i)
    {
        if (max(a[i],0) >= 25 - a[i])
        {
            int curr = a[i];
            if (k <= curr)
            {
                a[i] -= k;
                break;
            }
            k -= curr;
            a[i] = 0;
        }
        else
        {
            int curr = 25 - a[i];
            if (k <= curr)
            {
                a[i] += k;
                break;
            }
            k -= curr;
            a[i] = 25;
        }
    }
    for (int i=0; i<s.size(); ++i)
        cout<<(char)(a[i] + 'a');
    cout<<'\n';
    return 0;
}
