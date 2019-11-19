#include <iostream>

using namespace std;

int main()
{
    int t, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if (a == 1){
            if (b == 1){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
        else if (a <= 3){
            if (b < 4){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        } else {
            cout<<"YES\n";
        }
    }
    return 0;
}
