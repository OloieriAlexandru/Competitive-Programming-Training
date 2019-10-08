#include <iostream>
#define LMAX 105

using namespace std;

int n;
int a[LMAX];
int af;

int main()
{
    cin>>n;
    for (int i= 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i = 2;i<n;i++)
    {
        if (!a[i] && a[i-1] && a[i+1])
        {
            a[i+1] = 0;
            af++;
        }
    }
    cout<<af<<'\n';
    return 0;
}
