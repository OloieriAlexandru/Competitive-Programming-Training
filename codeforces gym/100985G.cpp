#include <bits/stdc++.h>
#define nmax
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
string s;
int main()
{
    cin>>s;
    stack<char>st;
    for (int i=0;i<s.size();++i)
    {
        if (s[i] == 'B' && st.empty())
        {
            printf("Nao\n");
            return 0;
        }
        if (s[i] == 'B')
            st.pop();
        else
            st.push('A');
    }
    if (!st.size())
        printf("Sim\n");
    else
        printf("Nao\n");
	return 0;
}
