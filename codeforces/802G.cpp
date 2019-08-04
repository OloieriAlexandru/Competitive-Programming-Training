#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    string f = "heidi";
    int act = 0;
    for (int i=0;i<s.size();++i)
    {
        if (s[i] == f[act])
        {
            ++act;
            if (act == 5)
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
