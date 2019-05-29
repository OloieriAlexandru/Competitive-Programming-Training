#include <iostream>
#define LMAX 1000005

using namespace std;

char a[LMAX];
char b[LMAX];
char c[LMAX];
int lgc;
int n;
char t;
char v;

int main()
{
    cin>>n;
    for (int i=0 ; i<n;i++)
    {
        cin>>a[n-i-1]>>b[n-i-1];
        a[n-i-1] -= '0';
        b[n-i-1] -= '0';
    }
    for (int i =0 ; i<n;i++)
    {
        v = a[i] + b[i] + t;
        c[i] = v%10;
        t = v/10;
    }
    lgc = n;
    if (t)
    {
        c[lgc++] = t;
    }
    for (int i= lgc-1;i>=0;i--)
    {
        cout<<(char)(c[i]+'0');
    }
    cout<<'\n';
    return 0;
}