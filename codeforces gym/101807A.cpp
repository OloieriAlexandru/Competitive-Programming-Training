#include <bits/stdc++.h>
using namespace std;

int main()
{
    double l, r, p;
    cin>>l>>r>>p;
    p /= 100.0;
    if (l < r){
        double pp = l / r;
        if (pp >= p){
            cout<<"Ambidextrous\n";
        } else {
            cout<<"Right-handed\n";
        }
    } else if (l > r){
        double pp = r / l;
        if (pp >= p){
            cout<<"Ambidextrous\n";
        } else {
            cout<<"Left-handed\n";
        }
    } else {
        cout<<"Ambidextrous\n";
    }
    return 0;
}
