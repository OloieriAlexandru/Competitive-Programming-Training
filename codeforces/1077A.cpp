#include <iostream>
#define lld long long int
using namespace std;

int t;
lld l, r, k;
lld dif;

int main()
{
    cin>>t;
    for (int q= 1;q<=t;q++)
    {
        cin>>l>>r>>k;
        dif = l-r;
        if (k%2==0)
        {
            cout<<(k/2)*dif<<'\n';
        }
        else
        {
            cout<<(k/2)*dif + l<<'\n';
        }
    }
    return 0;
}
