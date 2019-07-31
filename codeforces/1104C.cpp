#include <bits/stdc++.h>
using namespace std;
char ch;
bool ex1, ex2;
int main()
{
    while(cin>>ch)
    {
        if (ch == '0')
        {
            if (ex1)
                cout<<"3 1\n", ex1 = false;
            else
                cout<<"1 1\n", ex1 = true;
        }
        else
        {
            if (ex2)
                cout<<"4 1\n", ex2 = false;
            else
                cout<<"4 3\n", ex2 = true;
        }
    }
    return 0;
}
