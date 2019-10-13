#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int firstOne = -1, secondOne = -1;
        for (int i=0;i<s.size();++i)
            if (s[i] == '1')
        {
            if (firstOne == -1)
                firstOne = i;
            secondOne = i;
        }
        if (firstOne == -1)
            cout<<n<<'\n';
        else
        {
            int v1 = max(firstOne + 1, n - firstOne);
            int v2 = max(secondOne + 1, n - secondOne);
            int mul = max(v1, v2);
            cout << 2 * mul<<'\n';
        }
    }
    return 0;
}
