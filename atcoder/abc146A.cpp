#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax
#define mod
using namespace std;

int main()
{
    string s;
    cin>>s;
    if (s == "SAT"){
        cout<<"1\n";
    }
    else if (s == "FRI"){
        cout<<"2\n";
    }
    else if (s == "THU"){
        cout<<"3\n";
    }
    else if (s == "WED"){
        cout<<"4\n";
    }
    else if (s == "TUE"){
        cout<<"5\n";
    }
    else if (s == "MON"){
        cout<<"6\n";
    }
    else {
        cout<<"7\n";
    }
    return 0;
}
