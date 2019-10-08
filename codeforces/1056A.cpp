#include <iostream>

using namespace std;

int n;
int nr;
int x;
int fv[101];

int main()
{
    cin>>n;
    for (int i =1;i<=n;i++)
    {
        cin>>nr;
        for (int j = 1;j<=nr;j++)
        {
            cin>>x;
            fv[x]++;
        }
    }
    for (int i = 1;i<=100;i++)
    {
        if (fv[i]==n)
        {
            cout<<i<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
