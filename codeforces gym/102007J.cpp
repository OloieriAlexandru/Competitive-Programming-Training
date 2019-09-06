#include <bits/stdc++.h>
using namespace std;
double s1, s2, s3, s4;
double semip;
int main()
{
    cin>>s1>>s2>>s3>>s4;
    semip += (s1 + s2 + s3 + s4);
    semip /= 2.0;
    cout<<setprecision(10)<<fixed<<sqrt((semip-s1) * (semip-s2) * (semip-s3) * (semip-s4));
    return 0;
}
