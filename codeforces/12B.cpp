#include <bits/stdc++.h>
using namespace std;
string sa, sb;
int main()
{
    cin>>sa>>sb;
    sort(sa.begin(), sa.end());
    int act = 0;
    while (sa[act] == '0')
        ++act;
    if (act == sa.size()) --act;
    swap(sa[0], sa[act]);
    if (sa == sb)
        cout<<"OK\n";
    else
        cout<<"WRONG_ANSWER\n";
    return 0;
}
