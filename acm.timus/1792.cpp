#include <bits/stdc++.h>
#define nmax 10
using namespace std;
int v[nmax], cv[nmax];
const int n = 7;
bool hamming(int vec[nmax])
{
    int val1, val2, val3;
    val1 = (vec[2] + vec[3] + vec[4])%2;
    val2 = (vec[1] + vec[3] + vec[4])%2;
    val3 = (vec[1] + vec[2] + vec[4])%2;
    return (val1 == vec[5] && val2 == vec[6] && val3 == vec[7]);
}
void printEnd(int vec[nmax])
{
    for (int i=1;i<=n;++i)
        cout<<vec[i]<<' ';
    cout<<'\n';
    exit(0);
}
int main()
{
    for (int i=1;i<=n;++i)
        cin>>v[i];
    if (hamming(v))
        printEnd(v);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            cv[j] = v[j];
        cv[i] = !cv[i];
        if (hamming(cv))
            printEnd(cv);
    }
    return 0;
}
