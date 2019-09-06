#include <bits/stdc++.h>
using namespace std;
int n, month, day;
char ch;
string s;
int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int sum[13], act;
int has[800], fv[800];
int start;
void printDate(int x)
{
    int month = 1;
    for (int i=0; i<12; ++i)
    {
        if (x <= months[i])
        {
            if (month  < 10)
                cout<<0;
            cout<<month<<'-';
            if (x < 10)
                cout<<0;
            cout<<x<<'\n';
            break;
        }
        ++month;
        x-=months[i];
    }
    exit(0);
}
int main()
{
    cin>>n;
    sum[0] = months[0];
    for (int i=1; i<12; ++i)
        sum[i] = sum[i-1] + months[i];
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        cin>>month>>ch>>day;
        if (month == 1)
            act = day;
        else if (month == 2)
            act = day + sum[0];
        else
            act = day + sum[month-2];
        has[act] = 1;
        has[act + 365] = 1;
    }
    for (int i=1; i<=730; ++i)
        if (!has[i])
            fv[i] = fv[i-1] + 1;
        else
            fv[i] = 0;
    int maxx = 0;
    for (int i=1; i<=730; ++i)
        if (fv[i] > maxx)
            maxx = fv[i];
    start = 300;
    for (int i=start+1; i<=730; ++i)
        if (fv[i] == maxx)
            printDate(i>365?(i-365):i);
    for (int i=1; i<=start; ++i)
        if (fv[i] == maxx)
            printDate(i > 365?(i-365):i);
    return 0;
}
