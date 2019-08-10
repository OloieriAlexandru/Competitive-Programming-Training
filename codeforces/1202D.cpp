#include <bits/stdc++.h>
#define lld long long
#define nmax 70000
using namespace std;
lld p2[nmax];
vector<int>anses;
long long n;
long long maxx = 0;
int main()
{
    int t;
    cin>>t;
    for (lld i=2;1;++i)
    {
        p2[i-1] = i * (i-1) / 2;
        if ((i * (i-1) / 2 )> 1000000000) break;
        maxx = max(maxx, i);
    }
    while(t--)
    {
        cin>>n;
        anses.clear();
        for (int i=maxx;i>=1 && n;--i)
        {
            if (n >= p2[i])
            {
                n -= p2[i];
                anses.push_back(i);
            }
        }
        if (n == 1)
            anses.push_back(n);
        int rm = anses[0];
        int act = 0;
        for (int i=1;i<=rm;++i)
        {
            while (act < anses.size() && rm - i + 1 == anses[act])
            {
                cout<<1;
                ++act;
            }
            cout<<3;
        }
        cout<<"37\n";
    }
    return 0;
}
